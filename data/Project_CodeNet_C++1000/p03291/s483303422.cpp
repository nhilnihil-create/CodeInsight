#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll dp[n + 1][4] = {};
    dp[0][0] = 1;
    rep(i, 0, n) {
        rep(j, 0, 4) dp[i + 1][j] += dp[i][j];
        if (s[i] == 'A') dp[i + 1][1] += dp[i][0];
        if (s[i] == 'B') dp[i + 1][2] += dp[i][1];
        if (s[i] == 'C') dp[i + 1][3] += dp[i][2];
        if (s[i] == '?') {
            rep(j, 0, 4) dp[i + 1][j] *= 3;
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][2] += dp[i][1];
            dp[i + 1][3] += dp[i][2];
        }
        rep(j, 0, 4) dp[i + 1][j] %= MOD;
    }
    /*rep(i, 1, n + 1) {
        cout << dp[i][0] <<  " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
    }*/
    cout << dp[n][3] << endl;
    return 0;
}
