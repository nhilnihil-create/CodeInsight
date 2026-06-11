#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll m, k;
    cin >> m >> k;
    if (k == 0) {
        rrep(i, 1 << m) printf("%lld ", i);
        rep(i, 1 << m) printf("%lld%s", i, (i == ((1 << m) - 1)) ? "\n" : " ");
        return 0;
    }
    ll xv = 0;
    rep(i, 1 << m) {
        if (i != k) xv ^= i;
    }
    if (xv != k) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> ans(1 << (m + 1));
    ll idx = 0;
    rep(i, 1 << m) {
        if (i != k) ans[idx++] = i;
    }
    ans[idx++] = k;
    rrep(i, 1 << m) {
        if (i != k) ans[idx++] = i;
    }
    ans[idx++] = k;
    rep(i, sz(ans)) printf("%lld%s", ans[i], (i == (sz(ans) - 1)) ? "\n" : " ");
    return 0;
}
