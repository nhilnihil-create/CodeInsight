#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> X(N), Y(N), Z(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> X[i] >> Y[i] >> Z[i];
    }
    const ll INF = 1LL<<60;
    ll ans = -INF;
    ll dp[2][2][2][M+1];
    for ( int t1 = 0; t1 < 2; t1++ ) {
        for ( int t2 = 0; t2 < 2; t2++ ) {
            for ( int t3 = 0; t3 < 2; t3++ ) {
                dp[t1][t2][t3][0] = 0;
                for ( int j = 1; j <= M; j++ ) {
                    dp[t1][t2][t3][j] = -INF;
                }
                ll s1 = 1 - 2 * t1;
                ll s2 = 1 - 2 * t2;
                ll s3 = 1 - 2 * t3;
                for ( int i = 0; i < N; i++ ) {
                    for ( int j = M; j >= 1; j-- ) {
                        if ( dp[t1][t2][t3][j-1] == -INF ) continue;
                        ll x = dp[t1][t2][t3][j-1] + s1 * X[i] + s2 * Y[i] + s3 * Z[i];
                        dp[t1][t2][t3][j] = max(dp[t1][t2][t3][j], x);
                    }
                }
                ans = max(ans, dp[t1][t2][t3][M]);
            }
        }
    }
    
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}