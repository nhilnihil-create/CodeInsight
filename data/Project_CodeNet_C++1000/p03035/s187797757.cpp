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
    if (a >= 13) {
        cout << b << endl;
    } else if (a >= 6) {
        cout << b / 2 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}

