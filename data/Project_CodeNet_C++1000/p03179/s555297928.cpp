#include<bits/stdc++.h>

using namespace std;

using ll = long long;
#define long long long

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    cout << setprecision(16) << fixed;

    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<ll>> dp(n+1, vector<ll>(n));
    dp[0][0] = 1;
    for(ll i=0; i<n; i++) {
        partial_sum(dp[i].begin(), dp[i].end(), dp[i].begin(),
                [&](ll a, ll b){return (a+b) % MOD;});
        for(ll j=0; i+j<n; j++) {
            if(s[i] == '<')
                (dp[i+1][j] += dp[i][j]) %= MOD;
            else {
                (dp[i+1][0] += dp[i][j]) %= MOD;
                (dp[i+1][j] += MOD - dp[i][j]) %= MOD;
            }
        }
    }

    cout << dp[n-1][0] << endl;
}
