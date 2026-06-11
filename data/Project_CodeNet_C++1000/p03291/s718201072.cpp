#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;

ll dp[123456][4]; // dp[i][j] := i文字目までに"ABC"がj文字分完成している数

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    rep(i, S.size())
    {
        rep(j, 4)
        {
            if (S[i] != '?') {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            } else {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 3) % MOD;
            }
        }
        if (S[i] == 'A' || S[i] == '?')
            dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % MOD;
        if (S[i] == 'B' || S[i] == '?')
            dp[i + 1][2] = (dp[i + 1][2] + dp[i][1]) % MOD;
        if (S[i] == 'C' || S[i] == '?')
            dp[i + 1][3] = (dp[i + 1][3] + dp[i][2]) % MOD;
    }
    cout << dp[S.size()][3] << endl;
    return 0;
}