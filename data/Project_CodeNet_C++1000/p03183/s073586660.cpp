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

    int n;
    cin >> n;
    V<int> w(n), s(n), v(n), p(n);
    rep(i, n) {
        cin >> w[i] >> s[i] >> v[i];
        p[i] = i;
    }
    sort(ALL(p), [&](int a, int b) { return w[a] + s[a] < w[b] + s[b]; });
    V<ll> dp(20001, 0);
    for(int i : p) {
        int x = min(20000 - w[i], s[i]);
        FORR(j, x + 1) chmax(dp[j + w[i]], dp[j] + v[i]);
    }
    ll ans = 0;
    for(ll x : dp)
        chmax(ans, x);
    cout << ans << endl;

    return 0;
}