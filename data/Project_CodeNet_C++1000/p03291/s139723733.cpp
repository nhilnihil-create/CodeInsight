#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    string S;
    cin >> S;

    vector<vector<ll> > dp(S.size() + 1, vector<ll>(4));
    dp[0][0] = 1;

    ll mod = 7LL + 1e9;
    rep(i, S.size()) {
        rep(j, 4) {
            if (S[i] == '?') dp[i+1][j] += (3 * dp[i][j]) % mod;
            else dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= mod;
        }

        if (S[i] == 'A' || S[i] == '?') dp[i+1][1] += dp[i][0];
        if (S[i] == 'B' || S[i] == '?') dp[i+1][2] += dp[i][1];
        if (S[i] == 'C' || S[i] == '?') dp[i+1][3] += dp[i][2];

        rep(j, 4) {
            dp[i+1][j] %= mod;
        }
    }

    put(dp[S.size()][3]);
}
signed main(){ Main();return 0;}