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

namespace BasicMath {
    // 二つの値の最大値を求める関数
    static Int Max(const Int a, const Int b);
    // 最大公約数を求める(ユークリッドの互除法) 
    // O(log max(a, b)) time, O(1) space
    static UInt GreatestCommonDivisor(UInt a, UInt b);

    // 二つの値の最大値を求める関数
    Int Max(const Int a, const Int b) {
        if (a >= b) {
            return a;
        } else {
            return b;
        }
    }
    // 最大公約数を求める(ユークリッドの互除法) 
    UInt GreatestCommonDivisor(UInt a, UInt b) {
        if (b == 0) {
            return a;
        } else {
            if (a < b) {
                std::swap(a, b);
            }
            return GreatestCommonDivisor(b, a % b);
        }
    }
#define GCD GreatestCommonDivisor
}
using namespace BasicMath;

int main(void) {
    Int n;
    cin >> n;
    vector<Int> v(n);
    for (Int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<Int> l(n);
    vector<Int> r(n);
    l[0] = v[0];
    for (Int i = 1; i < n; ++i) {
        l[i] = GCD(l[i - 1], v[i]);
    }
    r[n - 1] = v[n - 1];
    for (Int i = n - 2; i >= 0; --i) {
        r[i] = GCD(r[i + 1], v[i]);
    }
    if (n == 2) {
        cout << Max(v[0], v[1]) << endl;
    } else {
        Int result = Max(r[0], r[1]);
        for (Int i = 0; i < n - 2; ++i) {
            result = Max(result, GCD(l[i], r[i + 2]));
        }
        result = Max(result, l[n - 2]);
        cout << result << endl;
    }
    return 0;
}

