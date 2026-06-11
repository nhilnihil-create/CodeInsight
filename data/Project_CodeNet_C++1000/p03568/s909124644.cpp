#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    ll a, n = 1, no = 1;
    for ( int i = 0; i < N; i++ ) {
        cin >> a;
        n *= 3;
        if ( a&1 ) {
            no *= 1;
        } else {
            no *= 2;
        }
    }
    ll ans = n - no;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}