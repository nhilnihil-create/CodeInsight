#include <iostream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n << endl;
    } else {
        cout << 2 * n << endl;
    }
    return 0;
}

