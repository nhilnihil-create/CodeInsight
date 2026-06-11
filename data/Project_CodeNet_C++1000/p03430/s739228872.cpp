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
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main
int main() {
    string s;
    int k;
    cin >> s >> k;
    
    vector<vector<vector<int>>> dp(s.size() + 1, vector<vector<int>>(s.size() + 1, vector<int>(k + 1, -1)));
    auto rec = [&](auto f, int l, int r, int m) -> int {
        if (dp[l][r][m] != -1) return dp[l][r][m];
        if (l == r) return dp[l][r][m] = 0;
        if (l + 1 == r) return dp[l][r][m] = 1;
        chmax(dp[l][r][m], f(f, l, r - 1, m));
        chmax(dp[l][r][m], f(f, l + 1, r, m));
        if (s[l] == s[r - 1]) chmax(dp[l][r][m], f(f, l + 1, r - 1, m) + 2);
        else if (m) chmax(dp[l][r][m], f(f, l + 1, r - 1, m - 1) + 2);
        return dp[l][r][m];
    };
    
    cout << rec(rec, 0, (int)s.size(), k) << "\n";
    return 0;
}
