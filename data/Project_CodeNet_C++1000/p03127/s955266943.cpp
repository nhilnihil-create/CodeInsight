#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>
 
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
    Int n;
    cin >> n;
    VI a(n);
    for (Int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Int result = a[0];
    for (Int i = 0; i < n; ++i) {
        result = GCD(result, a[i]);
    }
    cout << result << endl;

    return 0;
}

