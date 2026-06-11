/*
.....   .   .   .   .
  .    . .   . .   . .
  .   .....   .   .....
  .  .     .  .  .     .
*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <iomanip>
#include <random>
#include <sstream>
 
using namespace std;

#define int long long
#define double long double
#define time time228
#define left left228
#define right right228

template<typename T> void uin(T &a, T b) {
    if (b < a) a = b;
}

template<typename T> void uax(T &a, T b) {
    if (b > a) a = b;
}

const int maxn = 200 * 1000 + 228, MOD = 1e9 + 7;

int n;
int a[maxn], dp[maxn];
vector<int> g[maxn], rr[maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        uax(mx, a[i]);
        g[a[i]].push_back(i);
    }
    for (int c = 1; c <= mx; ++c) {
        for (int i = 0; i < (int)g[c].size() - 1; ++i) {
            if (g[c][i] + 1 < g[c][i + 1]) {
                int l = g[c][i], r = g[c][i + 1];
                rr[r].push_back(l);
            }
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        for (int l : rr[i]) {
            dp[i] += dp[l];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
