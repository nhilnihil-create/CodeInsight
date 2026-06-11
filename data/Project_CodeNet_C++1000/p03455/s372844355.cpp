#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int result = a * b;
    int c = result % 2;
    if (c == 0) {
        cout << "Even";
    }
    else {
        cout << "Odd";
    }
}