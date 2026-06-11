#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    const ll mod = 1e9 + 7;
    string s;
    cin >> s;
    ll sl = len(s);
    vector<vector<ll>> dp(sl + 1, vector<ll>(4, 0));
    dp[0][0] = 1;
    rep(i, sl) {
        rep(ii, sz(dp[i + 1])) {
            if (s[i] == '?') dp[i + 1][ii] = (dp[i][ii] * 3) % mod;
            else dp[i + 1][ii] = dp[i][ii];
        }
        if ((s[i] == 'A') || (s[i] == '?')) dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % mod;
        if ((s[i] == 'B') || (s[i] == '?')) dp[i + 1][2] = (dp[i + 1][2] + dp[i][1]) % mod;
        if ((s[i] == 'C') || (s[i] == '?')) dp[i + 1][3] = (dp[i + 1][3] + dp[i][2]) % mod;
    }
    cout << dp[sl][3] << endl;
    return 0;
}
