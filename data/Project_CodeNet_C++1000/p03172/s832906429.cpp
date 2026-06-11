#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        vector<ll> dr(m + 2, 0);
        for(int j = 0; j <= m; j++) {
            dr[j + 1] = (dr[j] + dp[i][j]) % MOD;
        }
        for(int j = 0; j <= m; j++) {
            dp[i + 1][j] = dr[j + 1] - dr[max(0LL, j - a[i])];
            dp[i + 1][j] = (dp[i + 1][j] + MOD) % MOD;
        }
    }
    cout << dp[n][m] << endl;
}
