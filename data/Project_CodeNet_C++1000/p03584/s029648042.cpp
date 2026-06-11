#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i] >> B[i];
    }
    ll ans = 0;
    ll k = K;
    bool f = true;
    while ( f || k > 0 ) {
        ll mask = f ? k : k-1;
        ll tmp = 0;
        for ( int i = 0; i < N; i++ ) {
            if ( (mask | A[i]) == mask ) {
                tmp += B[i];
           }
        }
        ans = max(ans, tmp);
        if ( !f ) {
            k = k & (k-1);
        } else {
            f = false;
        }
    }

    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}