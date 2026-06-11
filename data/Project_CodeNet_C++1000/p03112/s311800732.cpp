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
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    rep(i, a) cin >> s[i];
    rep(i, b) cin >> t[i];
    rep(i, q) {
        ll x;
        cin >> x;
        ll ans = LONG_LONG_MAX;
        auto its = lower_bound(all(s), x);
        auto itt = lower_bound(all(t), x);
        {
            if ((its != s.begin()) && (itt != t.begin())) {
                auto itst = its; itst--;
                auto ittt = itt; ittt--;
                ll tmp = x - min(*itst, *ittt);
                ans = min(ans, tmp);
            }
        }
        {
            if ((its != s.end()) && (itt != t.begin())) {
                auto ittt = itt; ittt--;
                ll tmp = (*its - x) + (x - *ittt) + min(*its - x, x - *ittt);
                ans = min(ans, tmp);
            }
        }
        {
            if ((its != s.begin()) && (itt != t.end())) {
                auto itst = its; itst--;
                ll tmp = (x - *itst) + (*itt - x) + min(x - *itst, *itt - x);
                ans = min(ans, tmp);
            }
        }
        {
            if ((its != s.end()) && (itt != t.end())) {
                ll tmp = max(*its, *itt) - x;
                ans = min(ans, tmp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
