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

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fls(x) (64 - __builtin_clzll(x))
#define pcnt(x) __builtin_popcountll(x)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll MOD = (ll)1e9 + 7;
    string s; cin >> s;
    int n = s.length();
    vector<vector<ll>> dp(n + 1, vector<ll>(4)), tmp(3, vector<ll>(4));
    dp[0][0] = 1;
    rep (i, s.length()) {
        if (s[i] == '?') {
            dp[i + 1][0] = 3 * dp[i][0] % MOD;
            rep (k, 3) {
                rep (j, 3) {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j + 1] + (k == j ? dp[i][j] : 0)) % MOD;
                }
            }
        } else {
            dp[i + 1][0] = dp[i][0];
            rep (j, 3) {
                dp[i + 1][j + 1] = (dp[i][j + 1] + (s[i] == (char)('A' + j) ? dp[i][j] : 0)) % MOD;
            }
        }
    }
    cout << dp[n][3] << "\n";
    rep (i, n + 1) eprintf("%3lld %3lld %3lld %3lld\n", dp[i][0], dp[i][1], dp[i][2], dp[i][3]);
    return 0;
}