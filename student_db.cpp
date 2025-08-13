#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Student {
    int roll;
    string name;
    int age;
};

vector<Student> db;

void saveData() {
    ofstream f("students.txt");
    for (auto &s : db)
        f << s.roll << " " << s.name << " " << s.age << "\n";
}

void loadData() {
    ifstream f("students.txt");
    Student s;
    while (f >> s.roll >> s.name >> s.age) db.push_back(s);
}

void addStudent() {
    Student s;
    cout << "Roll: "; cin >> s.roll;
    cout << "Name: "; cin >> s.name;
    cout << "Age: "; cin >> s.age;
    db.push_back(s);
    saveData();
}

void viewStudents() {
    for (auto &s : db)
        cout << s.roll << " " << s.name << " " << s.age << "\n";
}

void searchStudent() {
    int r; cout << "Enter roll to search: "; cin >> r;
    for (auto &s : db)
        if (s.roll == r) { cout << s.roll << " " << s.name << " " << s.age << "\n"; return; }
    cout << "Not found\n";
}

void deleteStudent() {
    int r; cout << "Enter roll to delete: "; cin >> r;
    for (auto it = db.begin(); it != db.end(); ++it)
        if (it->roll == r) { db.erase(it); saveData(); cout << "Deleted\n"; return; }
    cout << "Not found\n";
}

int main() {
    loadData();
    int ch;
    do {
        cout<<"\t\tStudent Database";
        cout << "\n1.Add 2.View 3.Search 4.Delete 5.Exit\nChoice: ";
        cin >> ch;
        if (ch==1) addStudent();
        else if (ch==2) viewStudents();
        else if (ch==3) searchStudent();
        else if (ch==4) deleteStudent();
    } while (ch != 5);
}

