#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> S, T;
    rp(i, 0, a) {
        ll s; cin >> s;
        S.emplace_back(s);
    }
    rp(i, 0, b) {
        ll t; cin >> t;
        T.emplace_back(t);
    }

    while(q--) {
        ll x; cin >> x;
        ll sr, sl, tr, tl;
        auto sitr = lower_bound(S.begin(), S.end(), x);
        auto titr = lower_bound(T.begin(), T.end(), x);
        if(sitr == S.begin()) {
            sr = *sitr;
            sl = -INF;
        }
        else if(sitr == S.end()) {
            sr = INF;
            sl = *(--sitr);
        } else {
            sr = *sitr;
            sitr--;
            sl = *sitr;
        }
        if(titr == T.begin()) {
            tr = *titr;
            tl = -INF;
        } else if(titr == T.end()) {
            tr = INF;
            tl = *(--titr);
        } else {
            tr = *titr;
            titr--;
            tl = *titr;
        }
        ll res1 = llabs(max(sr, tr) - x);
        ll res2 = llabs(min(sl, tl) - x);
        ll res3 = min(llabs(sl - x), llabs(tr - x)) + llabs(sl - tr);
        ll res4 = min(llabs(sr - x), llabs(tl - x)) + llabs(sr - tl);
        cout << min({res1, res2, res3, res4}) << endl;
    }
    return 0;
}
