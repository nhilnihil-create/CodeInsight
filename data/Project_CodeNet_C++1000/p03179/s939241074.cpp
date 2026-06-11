//#pragma  GCC optimize("Ofast")

//#ifdef  DEBUG
//#define _GLIBCXX_DEBUG
//#endif

// -Ofast
// -O3
// -O2
// -fsanitize=address
// -fsanitize=undefined

// add_compile_options()

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <unordered_map>
#include <cmath>
#include <cassert>
#include <random>

using namespace std;
//using namesparsace __gnu_pbds;

void solve();

int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    solve();
    return 0;
}

#define ld double
#define int long long

const int maxN = 3e3 + 10, maxK = 1e5 + 10, inf = 1e15 + 10, mod = 1e9 + 7, base = 223;

int n, dp[maxN][maxN], pref[maxN], suf[maxN];
string s;

void solve() {
    cin >> n >> s;
    dp[1][1] = 1;
    pref[1] = 1;
    pref[2] = 1;
    suf[1] = 1;
    suf[0] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (s[i - 2] == '>') {
                dp[i][j] = suf[j];
            } else {
                dp[i][j] = pref[j - 1];
            }
        }
        for (int j = 1; j <= i; j++) {
            pref[j] = (pref[j - 1] + dp[i][j]) % mod;
        }
        for (int j = i; j >= 1; j--) {
            suf[j] = (suf[j + 1] + dp[i][j]) % mod;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[n][i]) % mod;
    }
    cout << ans;
}

