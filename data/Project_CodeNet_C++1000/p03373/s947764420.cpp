#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = 0;
    ll h = min(X,Y);
    X -= h;
    Y -= h;
    if ( A + B <= 2 * C ) {
        ans += (A+B) * h;
    } else {
        ans += 2 * C * h;
    }
    if ( X != 0 ) {
        if ( A <= 2 * C ) ans += A * X;
        else ans += 2 * C * X;
    } else if ( Y != 0 ) {
        if ( B <= 2 * C ) ans += B * Y;
        else ans += 2 * C * Y;
    }

    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}