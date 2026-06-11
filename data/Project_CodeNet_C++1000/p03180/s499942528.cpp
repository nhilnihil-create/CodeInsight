#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            cin >> A[i][j];
        }
    }
    vector<ll> g(1<<N);
    for ( int b = 0; b < 1<<N; b++ ) {
        for ( int i = 0; i < N; i++ ) {
            for ( int j = i+1; j < N; j++ ) {
                if ( ((b >> i) & 1) && ((b >> j) & 1) ) g[b] += A[i][j];
            }
        }
    }
    vector<ll> dp(1<<N);
    for ( int b = 1; b < 1<<N; b++ ) {
        for ( int ms = b; ms > 0; ms--, ms &= b ) {
            dp[b] = max(dp[b], dp[b-ms] + g[ms]);
        }
    }
    return dp[(1<<N)-1];
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}