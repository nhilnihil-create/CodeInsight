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

    string s;
    cin >> s;
    int n = s.size();
    static int mn[1 << 26];
    fill(mn, mn + (1 << 26), mod);
    mn[0] = 0;
    int x = 0;
    rep(i, n) {
        x ^= 1 << s[i] - 'a';
        rep(j, 26) chmin(mn[x], mn[x ^ 1 << j] + 1);
    }
    cout << max(1, mn[x]) << endl;

    return 0;
}