#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Define a class for Student
class Student {
public:
    // Constructor
    Student(string name, int age, double gpa)
        : name_(std::move(name)), age_(age), gpa_(gpa) {}

    // Getter functions
    string getName() const {
        return name_;
    }

    int getAge() const {
        return age_;
    }

    double getGPA() const {
        return gpa_;
    }

private:
    string name_;
    int age_;
    double gpa_;
};

int main() {
    // Create a vector of Student objects
    vector<Student> students = {
        {"Ali", 20, 3.8},
        {"Bobi", 22, 3.5},
        {"Carmen", 21, 4.0},
        // Add more students as needed
    };

    // Sort the vector based on multiple criteria using lambda expressions
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        // Sort by GPA in descending order
        if (a.getGPA() != b.getGPA()) {
            return a.getGPA() > b.getGPA();
        }

        // If GPA is the same, sort by age in ascending order
        if (a.getAge() != b.getAge()) {
            return a.getAge() < b.getAge();
        }

        // If both GPA and age are the same, sort by name in lexicographical order
        return a.getName() < b.getName();
        });

    // Display the sorted list of students
    cout << "Sorted List of Students:\n";
    for (const auto& student : students) {
        cout << "Name: " << student.getName() << ", Age: " << student.getAge() << ", GPA: " << student.getGPA() << "\n";
    }

    return 0;
}
