#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, C, c;
    cin >> N >> C;
    vector<vector<ll>> D(C, vector<ll>(C));
    vector<vector<ll>> num_ini(3, vector<ll>(C));
    for ( int i = 0; i < C; i++ ) {
        for ( int j = 0; j < C; j++ ) {
            cin >> D[i][j];
        }
    }
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            cin >> c;
            c--;
            num_ini[(i+j+2)%3][c]++;
        }
    }
    // (i+j)%3=kのマスをk1に塗り替える時の違和感
    vector<vector<ll>> d(3, vector<ll>(C));
    for ( int t = 0; t < 3; t++ ) {
        for ( int k1 = 0; k1 < C; k1++ ) {
            for ( int k0 = 0; k0 < C; k0++ ) {
                if ( k1 == k0 ) continue;
                d[t][k1] += num_ini[t][k0] * D[k0][k1];
            }
        }
    }
    ll ans = 1e9;
    for ( int k0 = 0; k0 < C; k0++ ) {
        for ( int k1 = 0; k1 < C; k1++ ) {
            if ( k1 == k0 ) continue;
            for ( int k2 = 0; k2 < C; k2++ ) {
                if ( k2 == k0 || k2 == k1 ) continue;
                ll s = d[0][k0] + d[1][k1] + d[2][k2];
                ans = min(ans, s);
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