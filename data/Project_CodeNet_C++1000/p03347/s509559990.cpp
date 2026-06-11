#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    ll ans = 0;
    if ( A[0] != 0 ) return -1;
    for ( int i = 1; i < N; i++ ) {
        if ( A[i] > A[i-1] + 1 ) return -1;
        else if ( A[i] == A[i-1] + 1 ) ans++;
        else ans += A[i];
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}