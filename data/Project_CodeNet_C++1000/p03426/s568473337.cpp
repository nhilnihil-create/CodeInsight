//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int h, w, d;
    cin >> h >> w >> d;
    vvi a(h, vi(w));
    vector<P> mp(h*w+1);
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
            mp[a[i][j]] = P(i, j);
        }
    }

    int q;
    cin >> q;
    vi r(q), l(q);
    rep(i, q) {
        cin >> l[i] >> r[i];
    }

    vi sum(h*w+1);
    rep(i, h*w-d) {
        ++i;
        sum[i+d] = sum[i] + abs(mp[i+d].first - mp[i].first) + abs(mp[i+d].second - mp[i].second);
        --i;
    }

    rep(i, q) {
        cout << sum[r[i]] - sum[l[i]] << '\n';
    }
}