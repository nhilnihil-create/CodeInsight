//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int a, b;
    cin >> a >> b;
    int q;
    cin >> q;
    vector<ll> s(a), t(b);
    rep(i, a) {
        cin >> s[i];
    }
    rep(i, b) {
        cin >> t[i];
    }
    vector<ll> x(q);
    rep(i, q) {
        cin >> x[i];
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    rep(i, q) {
        auto str = upper_bound(s.begin(), s.end(), x[i]);
        auto ttr = upper_bound(t.begin(), t.end(), x[i]);
        ll sp = *str - x[i];
        ll sm = x[i] - *(str-1);
        ll tp = *ttr - x[i];
        ll tm = x[i] - *(ttr-1);
        if(str == s.begin()) {
            sm = INT64_MAX/10;
        }
        if(ttr == t.begin()) {
            tm = INT64_MAX/10;
        }
        if(str == s.end()) {
            sp = INT64_MAX/10;
        }
        if(ttr == t.end()) {
            tp = INT64_MAX/10;
        }

        ll mi = min({sp + abs(sp-tp), sp + sp + tm, sm + abs(sm-tm), 2*sm + tp, tp + abs(tp-sp), 2*tp + sm, tm + abs(tm-sm), 2*tm + sp});
        cout << mi << '\n';
    }
}