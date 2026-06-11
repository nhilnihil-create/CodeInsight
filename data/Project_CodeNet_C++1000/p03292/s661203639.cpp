#include <iostream>
#include <vector>
#include <string>
#include <cmath>
 
using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
 
// 基本的な演算
namespace BasicMath {
    // 二つの値の最大値を求める関数
    static Int Max(const Int a, const Int b);
    // 絶対値を求める
    static UInt Abs(const Int a);
    // 二つの値の最大値を求める関数
    Int Max(const Int a, const Int b) {
        if (a >= b) {
            return a;
        } else {
            return b;
        }
    }
    // 絶対値を求める
    UInt Abs(const Int a) {
        return a > 0 ? a : -a;
    }
}
using namespace BasicMath;
 
int main(void) {
    Int a, b, c;
    cin >> a >> b >> c;
    Int d, e, f;
    d = Abs(b - a);
    e = Abs(c - b);
    f = Abs(a - c);
    Int maxAbs = Max(Max(d, e), f);
    cout << d + e + f - maxAbs << endl;
    return 0;
}