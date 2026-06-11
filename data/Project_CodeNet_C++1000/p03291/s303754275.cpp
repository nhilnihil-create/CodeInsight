#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <string>
using namespace std;

#define int long long
#define rep(n, i) for (int i = 0; i < n; i++)
#define rep2(n, m, i) for (int i = m; i < n; i++)
#define rep_r(n, i) for (int i = n - 1; i >= 0; i--)

const int MOD = 1e9 + 7;
const int MAX_LEN = 1e5 + 1;

int dp[MAX_LEN][4];

signed main() {
    string s;
    cin >> s;
    const string ABC = "ABC";
    int len_s = s.size();
    dp[len_s][3] = 1;
    rep(3, i) {
        dp[len_s][i] = 0;
    }

    rep_r(len_s, i) {
        int m = (s[i] == '?') ? 3 : 1;
        dp[i][3] = m * dp[i + 1][3];
        dp[i][3] %= MOD;
        rep_r(3, j) {
            int m1 = m;
            int m2 = (s[i] == '?' || s[i] == ABC[j]) ? 1 : 0;
            dp[i][j] = m1 * dp[i + 1][j] + m2 * dp[i + 1][j + 1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[0][0] << endl;
}