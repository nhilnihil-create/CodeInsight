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
    Int a, b;
    cin >> a >> b;
    Int sum = a + b;
    Int diff = a - b;
    Int prod = a * b;
    cout << Max(Max(sum, diff), prod) << endl;
    return 0;
}
