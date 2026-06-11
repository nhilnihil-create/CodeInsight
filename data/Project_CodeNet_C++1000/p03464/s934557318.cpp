#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

ll solve() {
    ll K;
    cin >> K;
    vector<ll> A(K);
    for ( int i = 0; i < K; i++ ) {
        cin >> A[i];
    }
    auto upper_mul = [](ll x, ll m) {
        return x + m - 1 - (x + m - 1) % m;
    };
    auto lower_mul = [](ll x, ll m) {
        return x - x % m;
    };

    if ( A[K-1] != 2 ) return -1;
    pii ns(2,2);
    for ( int k = K-1; k >= 1; k-- ) {
        ll l = upper_mul(ns.first, A[k-1]);
        ll r = lower_mul(ns.second + A[k] - 1, A[k-1]);
        if ( l > r ) return -1;
        ns = pii(l,r);
    }
    cout << ns.first << " " << ns.second + A[0] - 1 << "\n";
    return 0;
}

int main() {
    auto ans = solve();
    if ( ans < 0 ) cout << ans << "\n";
    return 0;
}