#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

void PrintTable(const vector<vector<Int> >& table) {
    for (Int i = 0; i < (Int)table.size(); ++i) {
        for (Int j = 0; j < (Int)table[0].size(); ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

// ビット演算
namespace Bits {
    // 整数 x を左に i ビットシフトした値を返す
    static Int LeftBitShift(Int x, Int i);
    // 整数 x を右に i ビットシフトした値を返す
    static Int RightBitShift(Int x, Int i);
    // 整数x の 下から i 桁目が1かどうかを返す
    static bool IsFlagUp(Int x, Int i);
    // 整数x の 下から i 桁目が0かどうかを返す
    static bool IsFlagDown(Int x, Int i);

    // 整数 x を左に i ビットシフトした値を返す
    Int LeftBitShift(Int x, Int i) {
        return (x << i);
    }
    // 整数 x を右に i ビットシフトした値を返す
    Int RightBitShift(Int x, Int i) {
        return (x >> i);
    }
    // 整数x の 下から i 桁目が1かどうかを返す
    bool IsFlagUp(Int x, Int i) {
        return ((x & (1 << i)) != 0);
    }
    // 整数x の 下から i 桁目が0かどうかを返す
    bool IsFlagDown(Int x, Int i) {
        return ((x & (1 << i)) == 0);
    }
}
using namespace Bits;

int main(void) {
    Int n, m;
    cin >> n >> m;
    VVI table(m, VI(n, 0));
    for (Int i = 0; i < m; ++i) {
        Int k;
        cin >> k;
        for (Int j = 0; j < k; ++j) {
            Int s;
            cin >> s;
            --s;
            table[i][s] = 1;
        }
    }
    VI lightOn(m);
    for (Int i = 0; i < m; ++i) {
        cin >> lightOn[i];
    }
    Int loop = pow(2, n);
    Int result = 0;
    for (Int i = 0; i < loop; ++i) {
        bool lightFlag = true;
        for (Int j = 0; j < m; ++j) {
            // 点灯に関係するスイッチのうち，何個のスイッチがonになっているかを数える
            Int count = 0;
            for (Int k = 0; k < n; ++k) {
                if (table[j][k] == 1 && IsFlagUp(i, k)) {
                    ++count;
                }
            }
            if ((count % 2) == lightOn[j]) {
                // 点灯してる
            } else {
                // 点灯してない
                lightFlag = false;
            }
        }
        if (lightFlag) {
            result++;
        }
    }
    cout << result << endl;
    return 0;
}
