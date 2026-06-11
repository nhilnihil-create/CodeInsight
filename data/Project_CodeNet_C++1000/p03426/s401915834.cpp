#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    mat a(h, vec(w));
    vector<P> m(h*w);
    rep(i, h) rep(j, w) {
        cin >> a[i][j];
        --a[i][j];
        m[a[i][j]] = make_pair(i, j);
    }
    int q;
    cin >> q;
    vec l(q), r(q);
    rep(i, q) {
        cin >> l[i] >> r[i];
        --l[i];
        --r[i];
    }

    vec cost(h*w, 0);

    for (int i = d; i < h*w; i++) {
        cost[i] = cost[i-d];
        auto prev = m[i-d], now = m[i];
        cost[i] += abs(prev.first - now.first) + abs(prev.second - now.second);
    }

    rep(i, q) {
        int res = cost[r[i]] - cost[l[i]];
        cout << res << endl;
    }
    return 0;
}
