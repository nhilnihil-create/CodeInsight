#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A);
    rep(i, A) cin >> s[i];
    vector<ll> t(B);
    rep(i, B) cin >> t[i];
    vector<ll> x(Q);
    rep(i, Q) cin >> x[i];
    
    sort(all(s));
    sort(all(t));
    
    rep(i, Q) {
        auto si = lower_bound(all(s), x[i]) - s.begin();
        auto ti = lower_bound(all(t), x[i]) - t.begin();

        ll res = 1e18;
        if (1 <= si && 1 <= ti) {
            res = min(res, max(abs(x[i] - s[si-1]), abs(x[i] - t[ti-1])));
        }
        if (si < s.size() && ti < t.size()) {
            res = min(res, max(abs(x[i] - s[si]), abs(x[i] - t[ti])));
        }
        if (1 <= si && ti < t.size()) {
            res = min(res, 2 * abs(x[i] - s[si-1]) + abs(x[i] - t[ti]));
            res = min(res, abs(x[i] - s[si-1]) + 2 * abs(x[i] - t[ti]));
        }
        if (si < s.size() && 1 <= ti) {
            res = min(res, 2 * abs(x[i] - s[si]) + abs(x[i] - t[ti-1]));
            res = min(res, abs(x[i] - s[si]) + 2 * abs(x[i] - t[ti-1]));
        }

        put(res);
    }
}
signed main(){ Main();return 0;}