// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003LL;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> t(n), d(n);
    rep(i, n) {
        cin >> t[i] >> d[i];
        --t[i];
    }
    
    vector<int> nums(n);
    rep(i, n) nums[i] = i;
    sort(all(nums), [&](int x, int y) -> bool {return d[x] > d[y];});
    ll sum = 0;
    vector<int> cnt(n, 0);
    vector<vector<int>> vec(n);
    ll x = 0;
    rep(i, k) {
        sum += d[nums[i]];
        if (!cnt[t[nums[i]]]) ++x;
        ++cnt[t[nums[i]]];
        vec[t[nums[i]]].emplace_back(d[nums[i]]);
    }
    rep(i, n) sort(all(vec[i]));
    
    vector<int> yobun;
    rep(i, n) rep(j, (int)vec[i].size() - 1) yobun.emplace_back(vec[i][j]);
    sort(all(yobun));
    int now = 0;
    
    ll ans = sum + x * x;
    rep(i, k, n) {
        if (now == yobun.size()) break;
        if (cnt[t[nums[i]]]) continue;
        ++x;
        ++cnt[t[nums[i]]];
        sum -= yobun[now];
        sum += d[nums[i]];
        ++now;
        chmax(ans, sum + x * x);
    }
    
    cout << ans << "\n";
}
