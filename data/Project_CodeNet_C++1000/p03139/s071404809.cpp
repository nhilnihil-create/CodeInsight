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

// 二つの値の最小値を求める関数
Int Min(const Int a, const Int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}
// 二つの値の最大値を求める関数
Int Max(const Int a, const Int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    Int n, a, b;
    cin >> n >> a >> b;
    Int max, min;
    max = Min(a, b);
    min = Max(0, a + b - n);
    cout << max << " " << min << endl;
    return 0;
}
