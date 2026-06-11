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
    // 分数の Floor を求める関数
    static UInt Floor(const UInt a, const UInt b);

    // 分数の Ceil を求める関数
    UInt Ceil(const UInt a, const UInt b) {
        if (a % b == 0) {
            return a / b;
        } else {
            return a / b + 1;
        }
    }
    // 分数の Floor を求める関数
    UInt Floor(const UInt a, const UInt b) {
        return a / b;
    }
}
using namespace BasicMath;

int main(void) {
    int n;
    cin >> n;
    if (n == 0) {
        cout << '0' << endl;
    } else {
        vector<int> v;
        while (1) {
            //cout << "N = " << n << endl;
            if (n > 0) {
                v.push_back(n % 2);
                n = Floor(n, 2);
                n *= (-1);
                if (n == -1) {
                    break;
                }
            } else if (n < 0) {
                n *= (-1);
                v.push_back(n % 2);
                n = Ceil(n, 2);
                if (n == 1) {
                    break;
                }
            }
        }
        if (n == 1) {
            v.push_back(1);
        } else if (n == -1) {
            v.push_back(11);
        }
        for (Int i = v.size() - 1; i >= 0; --i) {
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}
