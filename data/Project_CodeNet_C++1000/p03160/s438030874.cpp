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

int n , a[maxn] , dp[maxn];

int32_t main() {
    FAST
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    fill(dp , dp + maxn , INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        if(i - 1 >= 0) {
            dp[i] = min(dp[i] , dp[i - 1] + abs(a[i] - a[i - 1]));
        }
        if(i - 2 >= 0) {
            dp[i] = min(dp[i] , dp[i - 2] + abs(a[i] - a[i - 2]));
        }
    }
    cout << dp[n - 1] << '\n';
}
