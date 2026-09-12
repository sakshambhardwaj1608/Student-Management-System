#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string course;
    float marks;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nCourse: " << course;
        cout << "\nMarks: " << marks << endl;
    }
};

void addStudent() {
    Student s;

    s.input();

    ofstream file("students.txt", ios::app);

    file << s.rollNo << endl;
    file << s.name << endl;
    file << s.course << endl;
    file << s.marks << endl;

    file.close();

    cout << "\nStudent added successfully!\n";
}

void displayStudents() {
    Student s;

    ifstream file("students.txt");

    while (file >> s.rollNo) {
        file.ignore();
        getline(file, s.name);
        getline(file, s.course);
        file >> s.marks;

        s.display();
    }

    file.close();
}

void searchStudent() {
    int roll;
    bool found = false;

    cout << "Enter Roll Number to search: ";
    cin >> roll;

    Student s;
    ifstream file("students.txt");

    while (file >> s.rollNo) {
        file.ignore();
        getline(file, s.name);
        getline(file, s.course);
        file >> s.marks;

        if (s.rollNo == roll) {
            s.display();
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "\nStudent not found!\n";
    }
}

void deleteStudent() {
    int roll;
    bool found = false;

    cout << "Enter Roll Number to delete: ";
    cin >> roll;

    Student s;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    while (file >> s.rollNo) {
        file.ignore();
        getline(file, s.name);
        getline(file, s.course);
        file >> s.marks;

        if (s.rollNo != roll) {
            temp << s.rollNo << endl;
            temp << s.name << endl;
            temp << s.course << endl;
            temp << s.marks << endl;
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent deleted successfully!\n";
    else
        cout << "\nStudent not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
