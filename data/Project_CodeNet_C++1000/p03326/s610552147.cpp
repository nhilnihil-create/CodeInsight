#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(int i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

ll dp[8][1001][1001] = {};
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    ll x[3][1000];
    rep (i, 8) rep (j, 1001) repp (k, 1, 1001) dp[i][j][k] = -1000000000000000;
    rep (i, n) rep (j, 3) cin >> x[j][i];
    rep (i, n) {
        rep (j, i + 1) {
            rep (k, 8) {
                ll tmp = 0;
                rep (l, 3) {
                    if (k & (1 << l)) tmp += x[l][i];
                    else tmp -= x[l][i];
                }
                chmax(dp[k][i + 1][j + 1], dp[k][i][j] + tmp);
                chmax(dp[k][i + 1][j], dp[k][i][j]);
            }
        }
    }
    rep (i, n + 1) {
        rep (j, i + 1) eprintf("%lld ", dp[7][i][j]);
        eprintf("\n");
    }
    ll ans = dp[0][n][m];
    rep (k, 8) chmax(ans, dp[k][n][m]);
    cout << ans << "\n";
    return 0;
}