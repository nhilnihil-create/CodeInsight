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
    // 絶対値を求める
    static UInt Abs(const Int a);

    // 絶対値を求める
    UInt Abs(const Int a) {
        return a > 0 ? a : -a;
    }
}
using namespace BasicMath;

int main(void) {
    UInt a, b, c, d;
    cin >> a >> b >> c >> d;
    if (Abs(b - a) <= d && Abs(c - b) <= d) {
        cout << "Yes" << endl;
    } else if (Abs(c - a) <= d) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
