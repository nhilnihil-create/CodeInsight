// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, r) for (int i = (l); i < (r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main Code
int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    a.push_back(-1);
    ++n;
    
    vector<pair<int, int>> vec(n);
    rep(i, n) vec[i] = pair<int, int>(a[i], i);
    sort(all(vec));
    int ans = inf, cnt = 0; // cnt: どこまで見たか
    vector<int> ng(n, false);
    while (true) {
        int cnt_ = n;
        rep(i, n) {
            if (a[i] == vec[cnt].first) {
                ng[i] = true;
            }
            if (a[i] > vec[cnt].first) {
                int idx = lower_bound(all(vec), pair<int, int>(a[i], -1)) - vec.begin();
                chmin(cnt_, idx);
            }
        }
        if (cnt_ == n) break;
        vector<int> num(n, -1);
        int j = 0;
        rep(i, n) {
            if (i) if (ng[i] && (!ng[i - 1])) ++j;
            if (!ng[i]) num[i] = j;
        }
        vector<int> c(j + 1, 0);
        rep(i, n) {
            if (!ng[i]) ++c[num[i]];
        }
        int mx = 0;
        int qc = 0;
        rep(i, cnt_, n) {
            if (c[num[vec[i].second]] >= k) {
                --c[num[vec[i].second]];
                ++qc;
                chmax(mx, vec[i].first);
            }
            if (qc == q) break;
        }
        if (qc == q) chmin(ans, mx - vec[cnt_].first);
        else break;
        cnt = cnt_;
    }
    
    cout << ans << "\n";
    return 0;
}
