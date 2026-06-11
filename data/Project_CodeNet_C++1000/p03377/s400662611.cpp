#include <iostream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int a, b, x;
    cin >> a >> b >> x;
    if (a > x) {
        cout << "NO" << endl;
    } else if (a + b < x) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
