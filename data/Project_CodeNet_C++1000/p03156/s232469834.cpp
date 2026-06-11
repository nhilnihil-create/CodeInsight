#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, A, B, p;
    cin >> N >> A >> B;
    vector<ll> n(3);
    for ( int i = 0; i < N; i++ ) {
        cin >> p;
        if ( p <= A ) n[0]++;
        else if ( p <= B ) n[1]++;
        else n[2]++;
    }
    ll ans = min({n[0],n[1],n[2]});
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}