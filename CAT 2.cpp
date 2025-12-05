//samuel daniel
//reg:BCS-03-0118/2025

#include <iostream>

using namespace std;

class Person {
protected:
    // Name is represented by an integer ID .
    int name;

public:
    // Constructor accepts an int
    Person(int n) : name(n) {
        cout << "-> Person object created for Name ID: " << name << endl;
    }

    // Public member function to set the name (now an int)
    void setName(int n) {
        name = n;
    }

    // Public member function to return the name (now an int)
    int getName() const {
        return name;
    }
};

class LibraryMember : public Person {
private:
    int memberID;
    int booksBorrowed;

public:
    // Constructor chains to Person's constructor
    LibraryMember(int name, int id, int borrowed)
        : Person(name), memberID(id), booksBorrowed(borrowed) {
        cout << "-> LibraryMember object created with ID: " << memberID << endl;
    }

    int getMemberID() const {
        return memberID;
    }

    int getBooksBorrowed() const {
        return booksBorrowed;
    }

    void displayMemberDetails() const {
        cout << "\n--- Library Member Details ---" << endl;
        cout << "  Name ID: " << getName() << endl;
        cout << "  ID: " << memberID << endl;
        cout << "  Books Borrowed: " << booksBorrowed << endl;
    }
};

class PremiumMember : public LibraryMember {
private:
    double membershipFee;

public:
    // Constructor chains up the hierarchy
    PremiumMember(int name, int id, int borrowed, double fee)
        : LibraryMember(name, id, borrowed), membershipFee(fee) {
        cout << "-> PremiumMember object created (Fee: $" << membershipFee << ")" << endl;
    }

    double getMembershipFee() const {
        return membershipFee;
    }

    // Overloaded display function
    void displayPremiumDetails() const {
        displayMemberDetails(); // Call the base class display
        cout << "  Membership Status: Premium" << endl;
        cout << "  Membership Fee: $" << membershipFee << endl; 
        cout << "------------------------------" << endl;
    }
};

int main() {
    cout << "--- Library Management System Demo ---\n" << endl;

    // 1. Create a standard LibraryMember object
    LibraryMember generalMember(50001, 1001, 3);
    generalMember.displayMemberDetails();

    cout << "\n----------------------------------------\n" << endl;

    // 2. Create a PremiumMember object
    PremiumMember premiumMember(50002, 2050, 5, 99.99);
    premiumMember.displayPremiumDetails();

    // Demonstrate inherited setName function
    premiumMember.setName(50003);
    cout << "\n[Updated Name ID for Robert]" << endl;
    cout << "  New Name ID: " << premiumMember.getName() << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}

