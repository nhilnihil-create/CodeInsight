#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, a, p;
    cin >> N;
    cin >> p;
    ll c = 1;
    ll ans = 0;
    for ( int i = 1; i < N; i++ ) {
        cin >> a;
        if ( a == p ) {
            c++;
        } else {
            ans += c / 2;
            c = 1;
        }
        p = a;
    }
    ans += c / 2;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}