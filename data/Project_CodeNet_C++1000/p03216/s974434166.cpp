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
template <typename T> inline bool chmin(T& x, const T& y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T& x, const T& y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Main
int main() {
    int n;
    string s;
    int q;
    cin >> n >> s >> q;
    
    rep(_, q) {
        int k;
        cin >> k;
        ll ans = 0, now = 0;
        int d_cnt = 0, m_cnt = 0;
        rep(i, k) {
            if (s[i] == 'D') ++d_cnt;
            if (s[i] == 'M') {
                ++m_cnt;
                now += d_cnt;
            }
            if (s[i] == 'C') ans += now;
        }
        rep(i, n - k) {
            if (s[i] == 'D') {
                --d_cnt;
                now -= m_cnt;
            }
            if (s[i] == 'M') --m_cnt;
            if (s[i + k] == 'D') ++d_cnt;
            if (s[i + k] == 'M') {
                ++m_cnt;
                now += d_cnt;
            }
            if (s[i + k] == 'C') ans += now;
        }
        cout << ans << "\n";
    }
    
    return 0;
}
