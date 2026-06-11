#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
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
    FORR(i, n) {
        if(t[i] == 'L' && R <= w) R++;
        if(t[i] == 'R' && L >= 1) L--;
        if(t[i] == 'U' && D <= h) D++;
        if(t[i] == 'D' && U >= 1) U--;
        if(s[i] == 'L') L++;
        if(s[i] == 'R') R--;
        if(s[i] == 'U') U++;
        if(s[i] == 'D') D--;
        if(L >= w || R <= 1 || U >= h || D <= 1) {
            puts("NO");
            return 0;
        }
    }
    puts(L < y && y < R && U < x && x < D ? "YES" : "NO");

    return 0;
}