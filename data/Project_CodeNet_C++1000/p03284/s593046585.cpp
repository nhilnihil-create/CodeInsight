#include <iostream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
int main(void) {
    Int n, k;
    cin >> n >> k;
    if (n % k == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
    return 0;
}

