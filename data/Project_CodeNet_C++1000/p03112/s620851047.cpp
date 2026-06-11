#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B);
    for (int i = 0; i < A; i++) cin >> s[i];
    for (int i = 0; i < B; i++) cin >> t[i];
    for (int i = 0; i < Q; i++) {
        ll x;
        cin >> x;
        auto sr = lower_bound(s.begin(), s.end(), x);
        auto tr = lower_bound(t.begin(), t.end(), x);
        bool srf = sr != s.end(), trf = tr != t.end();
        bool slf = sr != s.begin(), tlf = tr != t.begin();
        auto sl = sr, tl = tr;
        if (slf) sl--;
        if (tlf) tl--;
        ll res = LLONG_MAX;
        if (srf && trf) {
            res = min(res, max(*sr, *tr) - x);
        }
        if (slf && tlf) {
            res = min(res, x - min(*sl, *tl));
        }
        if (srf && tlf) {
            res = min(res, (*sr - *tl) + min(*sr-x, x-*tl));
        }
        if (slf && trf) {
            res = min(res, (*tr - *sl) + min(*tr-x, x-*sl));
        }
        cout << res << endl;
    }
}