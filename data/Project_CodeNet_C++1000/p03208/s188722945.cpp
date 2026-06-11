#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

// 基本的な演算
namespace BasicMath {
    // 二つの値の最小値を求める関数
    static Int Min(const Int a, const Int b);
    // 二つの値の最大値を求める関数
    static Int Max(const Int a, const Int b);
    // 二つの値の最大値を求める関数
    Int Max(const Int a, const Int b) {
        if (a >= b) {
            return a;
        } else {
            return b;
        }
    }
    // 二つの値の最小値を求める関数
    Int Min(const Int a, const Int b) {
        if (a <= b) {
            return a;
        } else {
            return b;
        }
    }
}
using namespace BasicMath;

int main(void) {
    Int n, k;
    cin >> n >> k;
    VI h(n);
    for (Int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    Int result = INT_MAX;
    for (Int i = 0; i <= n - k; ++i) {
        result = Min(result, h[i + k - 1] - h[i]);
    }
    cout << result << endl;
    return 0;
}

