#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"
using P = pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<P> l(n), r(n);
    rep(i, 0, n) {
        cin >> l[i].first >> r[i].first;
        l[i].second = r[i].second = i;
    }
    ll res = 0;
    rep(q, 0, 2) {
        sort(l.rbegin(), l.rend());
        sort(r.begin(), r.end());
        set<ll> usd;
        ll ans = 0, cur = 0;
        int i = 0, j = 0;
        for (i = 0; i < n; i++) {
            if (usd.count(l[i].second) == 0 && cur < l[i].first) {
                ans += l[i].first - cur;
                cur = l[i].first;
                usd.insert(l[i].second);
            }
            for (; j < n; j++) {
                if (usd.count(r[j].second) == 0 && cur > r[j].first) {
                    ans += cur - r[j].first;
                    cur = r[j].first;
                    usd.insert(r[j].second);
                    break;
                }
            }
        }
        res = max(ans + abs(cur), res);
        swap(l, r);
        rep(i, 0, n) {
            l[i].first *= -1;
            r[i].first *= -1;
        }
    }
    cout << res << endl;
    return 0;
}