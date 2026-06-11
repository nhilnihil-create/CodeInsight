#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
using Graph = vector<vector<pair<ll, ll>>>;


int main()
{
    string S;
    cin >> S;
    ll N = S.size(), MOD = 1e9+7;

    vvll dp(100010, vll(4));
    dp[0][0] = 1;

    rep(i, S.size()) {
        rep(j, 4) {
            if (S[i] == '?') dp[i+1][j] += dp[i][j] * 3;
            else dp[i+1][j] += dp[i][j];

            dp[i+1][j] %= MOD;

            if (j < 3 && (S[i] == "ABC"[j] || S[i] == '?')) {
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= MOD;
            }
        }
    }

    cout << dp[S.size()][3] << endl;
    return 0;
}