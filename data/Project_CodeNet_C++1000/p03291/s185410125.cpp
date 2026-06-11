#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <string>
#include <vector>

using namespace std;

long MOD = 1e9 + 7;
string s;

long dp(int pos, char next) {
    if (pos == s.size()) return next == 'D' ? 1 : 0;
    if (s[pos] == '?') {
        long consume = next != 'D' ? dp(pos + 1, next + 1) : 0;
        return (3 * dp(pos + 1, next) + consume) % MOD;
    } else {
        long consume = s[pos] == next ? dp(pos + 1, next + 1) : 0;
        return (dp(pos + 1, next) + consume) % MOD;
    }
}

int main() {
    cin >> s;

    vector<vector<long>> dp(s.size(), vector<long>(4));
    dp.push_back({0, 0, 0, 1});
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == '?') {
            for (char c = 'A'; c < 'D'; c++) {
                dp[i][c - 'A'] = (3 * dp[i + 1][c - 'A'] + dp[i + 1][c - 'A' + 1]);
            }
            dp[i]['D' - 'A'] = 3 * dp[i + 1]['D' - 'A'];
        } else {
            for (char c = 'A'; c < 'D'; c++) {
                if (s[i] == c) {
                    dp[i][c - 'A'] = dp[i + 1][c - 'A'] + dp[i + 1][c - 'A' + 1];
                } else {
                    dp[i][c - 'A'] = dp[i + 1][c - 'A'];
                }
            }
            dp[i]['D' - 'A'] = dp[i + 1]['D' - 'A'];
        }
        for (char c = 'A'; c <= 'D'; c++) {
            dp[i][c - 'A'] %= MOD;
        }
    }
    cout << dp[0][0] << endl;
}
