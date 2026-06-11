#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h, w, n;
    cin >> h >> w >> n;

    int L = 0, R = w + 1, U = 0, D = h + 1;

    int x, y;
    cin >> x >> y;

    string s, t;
    cin >> s >> t;

    for(int i = n - 1; i >= 0; i--) {
        if(t[i] == 'L' && R <= w) R++;
        if(t[i] == 'R' && 1 <= L) L--;
        if(t[i] == 'U' && D <= h) D++;
        if(t[i] == 'D' && 1 <= U) U--;
        if(s[i] == 'L') L++;
        if(s[i] == 'R') R--;
        if(s[i] == 'U') U++;
        if(s[i] == 'D') D--;
        if(w <= L || R <= 1 || h <= U || D <= 1) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << (L < y && y < R && U < x && x < D ? "YES\n" : "NO\n");

    return 0;
}