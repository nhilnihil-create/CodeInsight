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

namespace BasicMath {
    static Int Min(const Int a, const Int b);
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
    string s, t, u;
    cin >> s;
    t = ""; u = "";
    Int len = (Int)s.length();
    for (Int i = 0; i < len; ++i) {
        if (i % 2 == 0) {
            t += '0';
            u += '1';
        } else {
            t += '1';
            u += '0';
        }
    }
    Int difft = 0;
    Int diffu = 0;
    for (Int i = 0; i < len; ++i) {
        if (s[i] != t[i]) {
            difft++;
        }
        if (s[i] != u[i]) {
            diffu++;
        }
    }
    cout << Min(difft, diffu) << endl;
    return 0;
}

