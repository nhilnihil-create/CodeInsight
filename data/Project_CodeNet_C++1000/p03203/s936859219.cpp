#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

void solve();

signed main() {
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif // ONPC
    //freopen("time.in", "r", stdin);
    //freopen("time.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

const int N = 2e5 + 5;
int n, m, q, mn[N];
vector<int> v[N];

void solve() {
    cin >> n >> m >> q;
    int ans = n;
    int cur = 0;
    for (int i = 0; i < N; ++i) mn[i] = 1e9 + 7;
    set<pair<int, int>> Q;
    for (int i =1; i <= q; ++i) {
        int x, y;
        cin >> x >> y;
        v[y].pb(x);
        Q.insert({x, y});
    }
    for (int i= 0; i < N; ++i) {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
    }
    pair<int, int> p = {1, 1};
    bool f = 0;
    bool t = 0;
    while (1) {
        //cout << p.X << ' ' << p.Y << ' ' << cur << '\n';
        if (t == 0) {
            while (!v[p.Y].empty() && v[p.Y].back() < p.X) {
                v[p.Y].pop_back();
            }
            if (!v[p.Y].empty()) {
                ans = min(ans, v[p.Y].back() - p.X + cur);
            }
            if (p.X == n || Q.count({p.X + 1, p.Y})) {
                if (f) {
                    break;
                }
                f = 1;
            } else {
                ++p.X;
                f = 0;
            }
            ++cur;
        } else {
            if (p.Y == m || Q.count({p.X, p.Y + 1})) {

            } else {
                ++p.Y;
            }
        }
        t = 1 - t;
    }
    cout << min(cur, ans);
}
