#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;

int main() {
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A + 2);
    vector<ll> t(B + 2);
    vector<ll> x(Q);
    s[0]     = -1e11;
    s[A + 1] = 1e11;
    t[0]     = -1e11;
    t[B + 1] = 1e11;
    rep(i, A) cin >> s[i + 1];
    rep(i, B) cin >> t[i + 1];
    rep(i, Q) cin >> x[i];

    rep(i, Q) {
        ll sl = s[lower_bound(all(s), x[i]) - s.begin() - 1];
        ll sr = s[lower_bound(all(s), x[i]) - s.begin()];
        ll tl = t[lower_bound(all(t), x[i]) - t.begin() - 1];
        ll tr = t[lower_bound(all(t), x[i]) - t.begin()];

        ll p1 = x[i] - min(sl, tl);
        ll p2 = max(sr, tr) - x[i];
        ll p3 = 2 * sr - x[i] - tl;
        ll p4 = 2 * tr - x[i] - sl;
        ll p5 = x[i] - sl + tr - sl;
        ll p6 = x[i] - tl + sr - tl;
        cout << min({p1, p2, p3, p4, p5, p6}) << endl;
    }
}