#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

ll search(const vector<ll> &val, int l, int r) {
    ll b = ((l == 0) ? 0 : val[l - 1]);
    ll t = (val[r] - b) / 2, ans;
    while ((l + 1) < r) {
        int m = (l + r) / 2;
        if ((val[m] - b) >= t) r = m;
        else l = m;
    }
    if (abs(t - (val[l] - b)) >= abs(t - (val[r] - b))) ans = val[r];
    else ans = val[l];
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> dp(n);
    ll ans = LONG_LONG_MAX;
    rep(i, n) {
        if (i == 0) dp[i] = a[i];
        else dp[i] = dp[i - 1] + a[i];
    }
    reps(i, 1, n - 2) {
        ll p, q, r, s;
        ll ls = search(dp, 0, i);
        ll rs = search(dp, i + 1, n - 1);
        p = ls; q = dp[i] - ls;
        r = rs - dp[i]; s = (dp[n - 1] - dp[i]) - r;
        ans = min(ans, max(p, max(q, max(r, s))) - min(p, min(q, min(r, s))));
    }
    cout << ans << endl;
    return 0;
}