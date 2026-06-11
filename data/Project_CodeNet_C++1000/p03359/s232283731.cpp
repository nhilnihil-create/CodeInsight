#include <iostream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int a, b;
    cin >> a >> b;
    if (a <= b) {
        cout << a << endl;
    } else {
        cout << a - 1 << endl;
    }
    return 0;
}
