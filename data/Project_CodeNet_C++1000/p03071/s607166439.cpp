#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

int main(void) {
    Int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 2 * a << endl;
    } else if (a > b) {
        cout << 2 * a - 1 << endl;
    } else {
        cout << 2 * b - 1 << endl;
    }
    return 0;
}
