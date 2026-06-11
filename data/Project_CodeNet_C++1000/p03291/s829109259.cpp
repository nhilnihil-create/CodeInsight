#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    string S;
    cin >> S;
    ll n = S.size();
    const ll MOD = 1e9 + 7;
    auto Add = [&](ll& x, ll y) { x = ( x % MOD + y % MOD ) % MOD; };
    auto Mul = [&](ll& x, ll y) { x = ( x % MOD * y % MOD ) % MOD; };
    vector<vector<ll>> dp(n+2, vector<ll>(4, 0));
    dp[0][0] = 1;
    for ( int i = 1; i < n+2; i++ ) {
        char c = S[i-1];
        if ( c == '?' ) {
            for ( int j = 0; j <= 3; j++ ) {
                ll x = dp[i-1][j];
                Mul(x, 3);
                if ( j > 0 ) {
                    Add(x, dp[i-1][j-1]);
                }
                dp[i][j] = x;
            }
        } else {
            for ( int j = 0; j <= 3; j++ ) {
                dp[i][j] = dp[i-1][j];
            }
            int j = c - 'A' + 1;
            Add(dp[i][j], dp[i-1][j-1]);
        }
    }
    ll ans = dp[n+1][3];
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}