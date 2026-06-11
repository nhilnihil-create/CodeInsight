#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> X(3,vector<ll>(N));
    for ( int i = 0; i < N; i++ ) {
        cin >> X[0][i] >> X[1][i] >> X[2][i];
    }

    const ll INF = 1LL<<60;
    ll ans = -INF;
    int bw = 3;
    for ( int b = 0; b < 1<<bw; b++ ) {
        vector<ll> ns;
        for ( int i = 0; i < N; i++ ) {
            ll s = 0;
            for ( int ii = 0; ii < bw; ii++ ) {
                if ( (b >> ii) & 1 ) {
                    s -= X[ii][i];
                } else {
                    s += X[ii][i];
                }
            }
            ns.push_back(s);
        }
        sort(ns.rbegin(), ns.rend());
        ll ss = 0;
        for ( int j = 0; j < M; j++ ) {
            ss += ns[j];
        }
        ans = max(ans, ss);
    }
    
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}