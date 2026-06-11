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
}
using namespace BasicMath;

int main(void) {
    Int n;
    cin >> n;
    VI h(n);
    for (Int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    Int max_value = 0;
    for (Int i = 0; i < n; ++i) {
        max_value = Max(h[i], max_value);
    }
    h.push_back(-1); // ストッパー

    Int result = 0;
    for (Int i = 0; i < max_value; ++i) {
        for (Int j = 0; j < n; ++j) {
            if (h[j] > i) {
            } else {
                continue;
            }
            while (h[j] > i) {
                ++j;
            }
            result++;
        }
    }
    cout << result << endl;
}

