#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<unsigned long long int>;

int main(void) {
    Int a, b;
    cin >> a >> b;
    if (a % 2 == 1 && b % 2 == 1) {
        cout << "Odd" << endl;
    } else {
        cout << "Even" << endl;
    }
    return 0;
}
