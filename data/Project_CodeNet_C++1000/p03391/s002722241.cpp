#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

ll solve() {
    ll N, a, b;
    cin >> N;
    ll sum = 0, mn = INF;
    for ( int i = 0; i < N; i++ ) {
        cin >> a >> b;
        sum += a;
        if ( a > b ) {
            mn = min(mn, b);
        }
    }
    ll ans = sum - mn;
    if ( mn == INF ) ans = 0;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}