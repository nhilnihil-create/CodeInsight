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
    const int ma[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    sort(all(a));
    
    vector<int> mx(n + 1, -inf);
    auto rec = [&](auto f, int x) -> int {
        if (mx[x] != -inf) return mx[x];
        if (x == 0) return mx[x] = 0;
        mx[x] = -1;
        for (int i : a) {
            if (x < ma[i]) continue;
            int r = f(f, x - ma[i]);
            if (r != -1) chmax(mx[x], r + 1);
        }
        return mx[x];
    };
    rec(rec, n);
    
    int now = n;
    string ans;
    while (now) {
        int c = -1;
        for (int i : a) {
            if (now < ma[i]) continue;
            if (mx[now - ma[i]] == mx[now] - 1) {
                c = i;
            }
        }
        ans.push_back('0' + c);
        now -= ma[c];
    }
    
    cout << ans << "\n";
    return 0;
}
