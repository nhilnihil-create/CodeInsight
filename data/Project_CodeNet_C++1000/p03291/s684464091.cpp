#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
void modf(ll &a) {
    a = a % MOD;
}

int main() {
    string s;
    cin >> s;

    vector<vector<ll>> dp(s.size() + 1, vector<ll>(4));
    dp[0][0] = 1;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 4; j++) {
            if (s.at(i) == '?') {
                dp[i + 1][j] += dp[i][j] * 3;
                modf(dp[i + 1][j]);
            } else {
                dp[i + 1][j] += dp[i][j];
                modf(dp[i + 1][j]);
            }
        }

        if (s.at(i) == 'A' || s.at(i) == '?') {
            dp[i + 1][1] += dp[i][0];
            modf(dp[i + 1][1]);
        }
        if (s.at(i) == 'B' || s.at(i) == '?') {
            dp[i + 1][2] += dp[i][1];
            modf(dp[i + 1][2]);
        }
        if (s.at(i) == 'C' || s.at(i) == '?') {
            dp[i + 1][3] += dp[i][2];
            modf(dp[i + 1][3]);
        }
    }

    cout << dp[s.size()][3] << endl;
}