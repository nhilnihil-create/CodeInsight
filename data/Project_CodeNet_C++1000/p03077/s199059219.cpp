#include <iostream>
#include <iomanip>
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
    Int n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    Int min_value = a;
    min_value = Min(min_value, b);
    min_value = Min(min_value, c);
    min_value = Min(min_value, d);
    min_value = Min(min_value, e);
    cout << 5 + Ceil(n, min_value) - 1 << endl;
    return 0;
}

