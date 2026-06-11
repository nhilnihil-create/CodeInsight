#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 
int main() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    ll mx = x;
    ll my = y;
    for (ll i = 0; i < n; ++i) {
        ll u;
        cin >> u;
        mx = max(mx, u);
    }
    for (ll i = 0; i < m; ++i) {
        ll u;
        cin >> u;
        my = min(my, u);
    }

    if (mx < my) {
        cout << "No War" << endl;
    } else {
        cout << "War"  << endl;
    }
}
