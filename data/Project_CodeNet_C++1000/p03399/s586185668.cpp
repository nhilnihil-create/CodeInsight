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
    // 二つの値の最小値を求める関数
    static Int Min(const Int a, const Int b);
    static UInt UMin(const UInt a, const UInt b);
    // 二つの値の最小値を求める関数
    Int Min(const Int a, const Int b) {
        if (a <= b) {
            return a;
        } else {
            return b;
        }
    }
    UInt UMin(const UInt a, const UInt b) {
        if (a <= b) {
            return a;
        } else {
            return b;
        }
    }
}
using namespace BasicMath;

int main(void) {
    Int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << Min(a, b) + Min(c, d) << endl;
    return 0;
}
