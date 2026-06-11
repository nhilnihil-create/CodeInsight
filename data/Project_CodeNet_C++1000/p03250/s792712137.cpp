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
    Int a, b, c;
    cin >> a >> b >> c;
    Int maxNum = Max(Max(a, b), c);
    cout << a + b + c - maxNum + maxNum * 10 << endl;
    return 0;
}

