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

string s;
int n, k;
int dp[334][334][334];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> s >> k;
    n = s.size();
    rep(l, n) dp[l][l][0] = 1;
    FOR(bit, 1, n + 1) rep(l, n - bit + 1) {
        int r = l + bit - 1;
        rep(i, k + 1) {
            if(s[l] == s[r]) dp[l][r][i] = dp[l + 1][r - 1][i] + 2;
            if(i) chmax(dp[l][r][i], dp[l + 1][r - 1][i - 1] + 2);
            chmax(dp[l][r][i], dp[l + 1][r][i]);
            chmax(dp[l][r][i], dp[l][r - 1][i]);
            chmin<int>(dp[l][r][i], bit);
        }
    }
    cout << dp[0][n - 1][k] << endl;

    return 0;
}