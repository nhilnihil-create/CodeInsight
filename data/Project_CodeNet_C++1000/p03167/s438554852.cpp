#include <bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

#define int long long

#ifndef bhupixb
    #define var(...)
    #define stl(...)
#endif

#define rep(i,a,b) for (int i = a; i <= (int)b; ++i)
#define f first
#define s second

#define single_test


constexpr int mod = 1e9 + 7;

struct M {
    unsigned v;
    M(long long a = 0) : v((a %= mod) < 0 ? a + mod : a) {}
    M& operator+=(M r) { if ((v += r.v) >= mod) v -= mod; return *this; }
    M& operator-=(M r) { if ((v += mod - r.v) >= mod) v -= mod; return *this; }
    M& operator*=(M r) { v = (uint64_t)v * r.v % mod; return *this; }
};

uint32_t add(M a, M b) { return (a += b).v; }
uint32_t mul(M a, M b) { return (a *= b).v; }
uint32_t sub(M a, M b) { return (a -= b).v; }

uint32_t po(M x, int n) {
    M res(1);
    while (n > 0) {
        res *= (n & 1 ? x : 1);
        x *= x; n /= 2;
    }
    return res.v;
}

constexpr int maxn = 1003;

int32_t dp[maxn][maxn];
char s[maxn][maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> s[i][j];
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) continue;
            if (s[i][j] == '.') {
                dp[i][j] = add(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    #ifndef single_test
        cin >> t;
    #endif
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}