// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep3(i, l, r) for (ll i = (ll)(l); i < (ll)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
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
    string s;
    cin >> s;
    
    string a = string(s.begin(), s.begin() + s.size() / 2);
    string b = string(s.end() - s.size() / 2, s.end());
    reverse(all(a));
    
    if (s.size() & 1) {
        char c = s[s.size() / 2];
        rep(i, a.size()) {
            if (a[i] != c || b[i] != c) {
                cout << a.size() + i + 1 << "\n";
                return 0;
            }
        }
        cout << s.size() << "\n";
    } else {
        char c = a[0];
        rep(i, a.size()) {
            if (a[i] != c || b[i] != c) {
                cout << a.size() + i << "\n";
                return 0;
            }
        }
        cout << s.size() << "\n";
    }
}
