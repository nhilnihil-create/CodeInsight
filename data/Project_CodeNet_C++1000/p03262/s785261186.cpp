#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;

namespace BasicMath {
    // 最大公約数を求める(ユークリッドの互除法) 
    // O(log max(a, b)) time, O(1) space
    static UInt GreatestCommonDivisor(UInt a, UInt b);

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
    Int n, x;
    cin >> n >> x;
    VI v(n);
    for (Int i = 0; i < n; ++i) {
        cin >> v[i];
        v[i] = abs(v[i] - x);
    }
    sort(v.begin(), v.end());

    if (x == 1) { 
        cout << v[0] << endl;
    } else {
        UInt ans = GCD(v[0], v[1]);
        for (Int i = 2; i < n; ++i) {
            ans = GCD(ans, v[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
