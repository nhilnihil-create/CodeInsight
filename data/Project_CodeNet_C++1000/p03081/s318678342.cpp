//
// Created by Ильдар Ялалов on 14.01.2020.
//
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 8e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double dbl;
typedef unsigned int uint;
#define pb push_back
#define eb emplace_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define mp make_pair
#define all(a) a.begin(),a.end()


#ifdef zxc

#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

#else
#define debug(...) 42
#define debug_arr(...) 42
#endif

bool debug = 0;
const int MAXN = (4e5) + 100;
const int LOG = 21;
const int mod = 1e9 + 7;
const int MX = (2e7 + 10);


char s[MAXN];

char t[MAXN], d[MAXN];

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> t[i] >> d[i];
    }

    int l = 1, r = n;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;

        int v = mid;
        for (int i = 1; i <= q; ++i) {
            if (t[i] == s[v]) {
                if (d[i] == 'L') {
                    v--;
                } else {
                    v++;
                }
            }
            if (v == 0)
                break;
            if (v == n + 1)
                break;
        }
        debug(mid, v);


        if (v == 0) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    l = 1, r = n;
    int ans2 = -1;
    debug("start");
    while (l <= r) {
        int mid = (l + r) >> 1;
        int v = mid;
        for (int i = 1; i <= q; ++i) {
            if (t[i] == s[v]) {
                if (d[i] == 'L') {
                    v--;
                } else {
                    v++;
                }
            }
            if (v == 0)
                break;
            if (v == n + 1)
                break;
        }
        debug(mid, v);

        if (v == n + 1) {
            ans2 = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    debug(n);
    debug(ans, ans2);

    if (ans == -1 && ans2 == -1) {
        cout << n << "\n";
        return;
    }
    if (ans == -1 && ans2 != -1) {
        cout << ans2 - 1 << "\n";
        return;
    }
    if (ans2 == -1) {
        cout << n - ans << "\n";
        return;
    }
    if (ans2 <= ans) {
        cout << 0 << "\n";
    } else {
        cout << n - (ans + n - ans2 + 1) << "\n";
    }


}


// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES ( n==1)
signed main() {

#ifdef zxc
    freopen("../output.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#else
#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(15);


    int t = 1;
    while (t--) {
        solve();
    }
    debug(1.0 * clock() / CLOCKS_PER_SEC);
}