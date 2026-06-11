#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
 
int main(void) {
    Int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
