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
    ll n, z;
    cin >> n >> z;
    vector<ll> x(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
    }
    vector<ll> a(n), b(n), c(n), d(n);
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += v[i];
        a[i] = cur - x[i];
        b[i] = cur - x[i] - x[i];
        if (i) {
            a[i] = max(a[i], a[i - 1]);
            b[i] = max(b[i], b[i - 1]);
        } else {
            a[i] = max(a[i], 0LL);
            b[i] = max(b[i], 0LL);
        }
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--) {
        cur += v[i];
        c[i] = cur - z + x[i];
        d[i] = cur - z - z + x[i] + x[i];
        if (i != n - 1) {
            c[i] = max(c[i], c[i + 1]);
            d[i] = max(d[i], d[i + 1]);
        } else {
            c[i] = max(c[i], 0LL);
            d[i] = max(d[i], 0LL);
        }
    }
    ll ans = max(a[n - 1], c[0]);
    for (int i = 0; i < n - 1; i++) {
        ans = max({ans, a[i] + d[i + 1], b[i] + c[i + 1]});
    }
    cout << ans << '\n';
    return 0;
}