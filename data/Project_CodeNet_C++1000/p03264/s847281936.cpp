#include <iostream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int k;
    cin >> k;
    if (k % 2 == 0) {
        cout << (k / 2) * (k / 2) << endl;
    } else {
        cout << (k / 2 + 1) * (k / 2) << endl;
    }
    return 0;
}

