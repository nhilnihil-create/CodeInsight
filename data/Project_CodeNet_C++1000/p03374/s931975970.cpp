#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //    freopen("out", "w", stdout);
#endif
    //    ios::sync_with_stdio(0), cin.tie(0);
    ll n, c;
    scanf("%lld%lld", &n, &c);
    vector<ll> x(n), v(n), F(n), B(n), mxf(n), mxb(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &v[i]);
    }

    F[0] = v[0];
    for (int i = 1; i < n; i++)
        F[i] = F[i - 1] + v[i];
    for (int i = 0; i < n; i++)
        F[i] -= x[i];
    mxf[0] = F[0];
    for (int i = 1; i < n; i++)
        mxf[i] = max(F[i], mxf[i - 1]);

    B[0] = v[n - 1];
    for (int i = 1; i < n; i++)
        B[i] = B[i - 1] + v[n - i - 1];
    for (int i = 0; i < n; i++)
        B[i] -= (c - x[n - i - 1]);
    mxb[0] = B[0];
    for (int i = 1; i < n; i++)
        mxb[i] = max(B[i], mxb[i - 1]);
    
    ll ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        ll cur = F[i];
        if (i != n - 1)
            cur = max(cur, cur + mxb[n - 2 - i] - x[i]);
        ans = max(ans, cur);
    }

    ll res = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        ll cur = B[i];
        if (i != n - 1)
            cur = max(cur, cur + mxf[n - 2 - i] - (c - x[n - 1 - i]));
        res = max(res, cur);
    }
    
    cout << max({0LL, res, ans}) << endl;

    return 0;
}
