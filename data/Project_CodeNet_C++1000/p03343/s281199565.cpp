#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll INF = 1LL<<60;
    ll N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }

    auto check = [&](ll m) {
        vector<vector<ll>> v;
        v.push_back(vector<ll>());
        for ( int i = 0; i < N; i++ ) {
            if ( A[i] > m ) {
                v[v.size()-1].push_back(A[i]);
            } else {
                v.push_back(vector<ll>());
            }
        }
        ll c = 0;
        for ( auto u : v ) {
            c += max((ll)(u.size() - K + 1), 0LL);
        }
        if ( c < Q ) return INF;
        vector<ll> w;
        for ( auto u : v ) {
            if ( u.size() < K ) continue;
            sort(u.begin(), u.end());
            for ( int j = 0; j < u.size() - K + 1; j++ ) {
                w.push_back(u[j]);
            }
        }
        sort(w.begin(), w.end());
        return w[Q-1] - w[0];
    };
    ll ans = check(0);
    for ( int i = 0; i < N; i++ ) {
        ans = min(ans, check(A[i]));
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}