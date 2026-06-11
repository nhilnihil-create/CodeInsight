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

// 基本的な演算
//namespace BasicMath {
    // 絶対値を求める
    static inline UInt Abs(const Int a);
    // 二つの値の最小値を求める関数
    static inline Int Min(const Int a, const Int b);
    // 絶対値を求める
    UInt Abs(const Int a) {
        return a > 0 ? a : -a;
    }
    // 二つの値の最小値を求める関数
    Int Min(const Int a, const Int b) {
        if (a <= b) {
            return a;
        } else {
            return b;
        }
    }
//}
//using namespace BasicMath;

// ビット演算
//namespace Bits {
    // 整数x の 下から i 桁目が1かどうかを返す
    static inline bool IsFlagUp(Int x, Int i);
    // 整数x の 下から i 桁目が1かどうかを返す
    bool inline IsFlagUp(Int x, Int i) {
        return ((x & (1 << i)) != 0);
    }
//}
//using namespace Bits;

int main(void) {
    Int n, a, b, c;
    cin >> n >> a >> b >> c;
    VI l(n);
    for (Int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    Int size = pow(2, n);
    VI bamboo(size);
    VI cost(size);
    for (Int i = 0; i < size; ++i) {
        bamboo[i] = 0;
        cost[i] = 0;
        for (Int j = 0; j < n; ++j) {
            if (IsFlagUp(i, j)) {
                bamboo[i] += l[j];
                cost[i]++;
            }
        }
    }
    VI da(size);
    VI db(size);
    VI dc(size);
    for (Int i = 1; i < size; ++i) {
        da[i] = Abs(bamboo[i] - a) + 10 * (cost[i] - 1);
        db[i] = Abs(bamboo[i] - b) + 10 * (cost[i] - 1);
        dc[i] = Abs(bamboo[i] - c) + 10 * (cost[i] - 1);
    }
    Int answer = INT_MAX;
    for (Int i = 1; i < size; ++i) {
        for (Int j = 1; j < size; ++j) {
            for (Int k = 1; k < size; ++k) {
                bool flag = true;
                for (Int x = 0; x < n; ++x) {
                    bool xa = IsFlagUp(i, x);
                    bool xb = IsFlagUp(j, x);
                    bool xc = IsFlagUp(k, x);
                    if (xa && xb) {
                        flag = false;
                    }
                    if (xb && xc) {
                        flag = false;
                    }
                    if (xc && xa) {
                        flag = false;
                    }
                }
                if (flag) {
                    answer = Min(answer, da[i] + db[j] + dc[k]);
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}

