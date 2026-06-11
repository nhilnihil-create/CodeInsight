#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    vector<ll> A(5);
    for ( int i = 0; i < 5; i++ ) cin >> A[i];
    ll s = 0, mx = 0;
    for ( int i = 0; i < 5; i++ ) {
        s += (A[i]+10-1)/10*10;
        mx = max(mx, (10-A[i]%10)%10);
    }
    ll ans = s-mx;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}