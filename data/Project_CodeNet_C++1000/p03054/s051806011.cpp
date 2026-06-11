// Template
#pragma region r1
#include "bits/stdc++.h"
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003LL;
template <typename T>
inline bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T> 
inline bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}
struct IOSET {
    IOSET() {
        cin.tie(0);
        ios::sync_with_stdio(0);
        cout << fixed << setprecision(10);
    }
} ioset;
#pragma endregion

// Main Code
int main() {
    int h, w, n, sr, sc;
    cin >> h >> w >> n >> sr >> sc;
    --sr; --sc;
    string s, t;
    cin >> s >> t;

    int a = 0, b = h, c = 0, d = w;
    per(i, n) {
        if (t[i] == 'L') d = min(d + 1, w);
        if (t[i] == 'R') c = max(c - 1, 0);
        if (t[i] == 'U') b = min(b + 1, h);
        if (t[i] == 'D') a = max(a - 1, 0);
        if (s[i] == 'L') c = min(c + 1, w);
        if (s[i] == 'R') d = max(d - 1, 0);
        if (s[i] == 'U') a = min(a + 1, h);
        if (s[i] == 'D') b = max(b - 1, 0);
        if (a == b || c == d) {
            cout << "NO\n";
            return 0;
        }
    }
    if (a <= sr && sr < b && c <= sc && sc < d) cout << "YES\n";
    else cout << "NO\n";
}