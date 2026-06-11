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
    cin >> s;
    s += "##";
    
    vector<int> memo(s.size() - 2, -1);
    ll ans = 0;
    per(i, s.size() - 2) {
        if (s[i] != 'A') continue;
        memo[i] = 0;
        int now = i + 1;
        while (true) {
            if (s[now] == 'A') {
                memo[i] += memo[now];
                break;
            }
            if (s[now] != 'B') break;
            ++now;
            if (s[now] != 'C') break;
            ++now;
            ++memo[i];
        }
        ans += memo[i];
    }
    
    cout << ans << "\n";
}
