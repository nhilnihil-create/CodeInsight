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


const int max_nodes = 22;
using edge = int32_t;
vector<edge> g[max_nodes];
void add_edge(int u, int v) {
    g[u].emplace_back(v);
}


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


int n, mx;
int dp[1 << 21];

int go(int mask) {
    if (mask == mx) {
        return 1;
    }
    int pos = __builtin_popcount(mask);
    auto &ref = dp[mask];
    if (ref != -1) {
        return ref;
    }
    int ans = 0;
    // var(pos);
    for (int adj: g[pos]) {
        if (!((mask >> adj) & 1)) {
            ans = add(ans, go(mask | (1 << adj)));
        }
    }
    return ref = ans;
}

void solve() {
    cin >> n;
    int x;
    memset(dp, -1, sizeof dp);
    rep(i,0,n-1) {
        rep(j,0,n-1) {
            cin >> x;
            if (x) {
                add_edge(i, j);
            }
        }
    }
    mx = (1 << n) - 1;
    cout << go(0) << '\n';
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