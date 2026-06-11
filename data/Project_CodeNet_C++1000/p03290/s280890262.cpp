#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<unsigned long long int>;

// 基本的な演算
namespace BasicMath {
    // 分数の Ceil を求める関数
    static UInt Ceil(const UInt a, const UInt b);
    // 二つの値の最小値を求める関数
    static Int Min(const Int a, const Int b);

    // 分数の Ceil を求める関数
    UInt Ceil(const UInt a, const UInt b) {
        if (a % b == 0) {
            return a / b;
        } else {
            return a / b + 1;
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
    Int d, g;
    cin >> d >> g;
    VI c(d + 1);
    VI p(d + 1);
    for (Int i = 1; i <= d; ++i) {
        cin >> c[i] >> p[i];
    }

    Int result = INT_MAX;
    Int comb = pow(2, d);

    for (Int i = 0; i < comb; ++i) {
        Int cost = 0;
        Int loop_result = 0;
        for (Int j = 1; j <= d; ++j) {
            if (i & (1 << (j - 1))) {
                cost += (100 * j * c[j] + p[j]);
                loop_result += c[j];
            }
        }
        if (cost >= g) {
            result = min(result, loop_result);
        } else {
            Int diff = g - cost;
            for (Int j = 1; j <= d; ++j) {
                if ((i & (1 << (j - 1))) == 0) {
                    if (diff <= (c[j] * 100 * j)) {
                        result = Min(result, loop_result + Ceil(diff, 100 * j));
                    }
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}
