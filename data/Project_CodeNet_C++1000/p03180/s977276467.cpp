#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int n;
ll dp[1 << 16], a[16][16];

ll f(int S) {
    if(dp[S] != -1) return dp[S];

    dp[S] = 0;
    rep(i, n) if(S >> i & 1) rep(j, i) if(S >> j & 1) dp[S] += a[i][j];

    for(int T = S - 1 & S; T > (S ^ T); T = T - 1 & S)
        chmax(dp[S], f(T) + f(S ^ T));

    return dp[S];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(i, 1 << n) dp[i] = -1;

    cout << f((1 << n) - 1) << endl;

    return 0;
}