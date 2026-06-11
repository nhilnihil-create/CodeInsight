#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    if (a == b) {
        cout << 0 << '\n';
        return 0;
    }
    ll ans = 0;
    ll dif = 0;
    ll s = 1e18, t = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) {
            ans += a[i];
            dif += b[i] - a[i];
        } else {
            s = min(s, b[i]);
            ans += a[i];
        }
    }
    cout << ans - s << '\n';
    return 0;
}
