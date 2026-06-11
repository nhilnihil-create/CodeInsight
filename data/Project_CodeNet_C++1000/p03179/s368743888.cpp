#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <cstdint>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
using i64 = int64_t;
const i64 mod = 1e9 + 7;
i64 n, dp[3001][3001];
string s;
int main() {
    cin >> n >> s;
    s.insert(begin(s), '*');
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1;
    }
    for (i64 i = 1; i < n; ++i) {
        if (s[i] == '<') {
            for (i64 j = 1; j <= n - i; ++j) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        } else {
            for (i64 j = n - i; j >= 1; --j) {
                dp[i][j] = (dp[i - 1][j + 1] + dp[i][j + 1]) % mod;
            }
        }
    }
    cout << dp[n - 1][1] << endl;
    return 0;
}