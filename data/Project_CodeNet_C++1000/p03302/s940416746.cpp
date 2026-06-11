#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

int main(void) {
    Int a, b;
    cin >> a >> b;
    if (a + b == 15) {
        cout << '+' << endl;
    } else if (a * b == 15) {
        cout << '*' << endl;
    } else {
        cout << 'x' << endl;
    }
    return 0;
}
