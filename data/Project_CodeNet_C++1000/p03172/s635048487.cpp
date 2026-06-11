#include <bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

// #define int long long

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

const int maxn = 1e5 + 3;

int dp[101][maxn];

int get(int l, int r, int id) {
     if (l <= 0) return dp[id][r];
    return sub(dp[id][r], dp[id][l - 1]);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // base cases are important and should be carefully managed
    for (int i = 0; i <= a[1]; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = 1;
        int val = a[i];
        for (int j = 1; j < maxn; ++j) {
            dp[i][j] = get(j - val, j, i - 1);
        }
        for (int j = 1; j < maxn; ++j) {
            dp[i][j] = add(dp[i][j], dp[i][j - 1]);
        }
    }
    // rep(i,1,n) rep(j,0,k) cout << dp[i][j] << " \n"[j == k];
    cout << dp[n][k] << '\n';
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