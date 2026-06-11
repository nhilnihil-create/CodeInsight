#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    ll c;
    cin >> n >> c;
    vt<ll> x(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
    }

    ll ans = 0;

    vt<ll> psl(n + 1);
    for (int i = 0; i < n; i++) {
        psl[i + 1] = psl[i] + v[i];
    }
    vt<ll> mxl(psl);
    for (int i = 0; i < n; i++) {
        mxl[i + 1] -= 2 * x[i];
    }
    for (int i = 0; i < n; i++) {
        mxl[i + 1] = max(mxl[i], mxl[i + 1]);
    }

    vt<ll> psr(n + 1);
    for (int i = 0; i < n; i++) {
        psr[n - i - 1] = psr[n - i] + v[n - i - 1];
    }
    vt<ll> mxr(psr);
    for (int i = 0; i < n; i++) {
        mxr[n - i - 1] -= 2 * (c - x[n - i - 1]);
    }
    for (int i = 0; i < n; i++) {
        mxr[n - i - 1] = max(mxr[n - i], mxr[n - i - 1]);
    }

    for (int i = 0; i <= n; i++) {
        ans = max({
            ans,
            psl[i] - (i ? x[i - 1] : 0) + mxr[i],
            psr[i] - (i != n ? c - x[i] : 0) + mxl[i]
        });
    }

    cout << ans;
}
