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
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T& x, const T& y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T& x, const T& y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(15);}} ioset;

int n;
long double dp[301][301][301];
bool flag[301][301][301];

long double rec(int i, int j, int k) {
    if (flag[i][j][k]) return dp[i][j][k];
    if (i + j + k == 0) return 0.0;
    double x = 0;
    if (i) x += rec(i - 1, j, k) * i / (i + j + k);
    if (j) x += rec(i + 1, j - 1, k) * j / (i + j + k);
    if (k) x += rec(i, j + 1, k - 1) * k / (i + j + k);
    flag[i][j][k] = true;
    return dp[i][j][k] = x + (double)n / (i + j + k);
}

int main() {
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> cnt(3, 0);
    rep(i, n) ++cnt[a[i] - 1];
    cout << rec(cnt[0], cnt[1], cnt[2]) << "\n";
    return 0;
}
