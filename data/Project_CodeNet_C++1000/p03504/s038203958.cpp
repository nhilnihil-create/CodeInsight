#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, C, s, t, c;
    cin >> N >> C;
    ll M = 1e5;
    vector<vector<ll>> d(C, vector<ll>(M+2));
    for ( int n = 0; n < N; n++ ) {
        cin >> s >> t >> c;
        c--;
        for ( int i = s; i <= t; i++ ) {
            d[c][i] = 1;
        }
    }
    ll m = 0, nm = 0;
    for ( int i = 0; i < M+2; i++ ) {
        ll a = 0;
        for ( int c = 0; c < C; c++ ) {
            a += d[c][i];
        }
        m = max(m, a);
    }
    return m;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}