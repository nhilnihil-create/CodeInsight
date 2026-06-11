#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define ll long long
#define int long long
#define ld long double
#define pii pair <int , int>
#define pll pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

const int maxn = 3e5 , N = 1e5 + 5 , SQ = 600 , base = 1999 , mod = 1e9 + 7 , INF = 1e18 , lg = 17;

int n , a[maxn][3] , dp[maxn][3];

int32_t main() {
    FAST
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    for( int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[i][j] = -INF;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int t = 0; t < 3; ++t) {
                if(t != j) {
                    dp[i][j] = max(dp[i][j] , dp[i - 1][t] + a[i - 1][j]);
                }
            }
        }
    }

    cout << max(dp[n][0] , max(dp[n][1] , dp[n][2])) << '\n';
}
