#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll a, ll b) {
    ll m = a * b;
    ll r = sqrt(m) - 2;
    while ( (r+1) * (r+1) < m ) r++;
    ll r2 = r * (r+1) < m ? r+1 : r;
    ll ans;
    if ( r != r2 ) {
        if ( a == r+1 && b == r+1 ) {
            ans = 2 * r;
        } else {
            ans = 2 * r - 1;
        }
    } else {
        ans = 2 * r - 2;
    }
    return ans;
}

int main() {
    ll Q, a, b;
    cin >> Q;
    for ( int q = 0; q < Q; q++ ) {
        cin >> a >> b;
        auto ans = solve(a,b);
        cout << ans << "\n";
    }
    return 0;
}