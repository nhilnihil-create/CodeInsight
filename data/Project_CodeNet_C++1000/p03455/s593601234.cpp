#include <iostream>
using namespace std;

int a, b;
int main() {
    cin >> a >> b;
    if(a >= 1 && b >=1 && a*b % 2 != 0) {
        cout << "Odd" << endl;
    } else if(a >= 1 && b >=1 && a*b % 2 == 0) {
        cout << "Even" << endl;
    }
}