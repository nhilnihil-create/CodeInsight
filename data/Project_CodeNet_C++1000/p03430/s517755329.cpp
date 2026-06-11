#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 307;
int n, k, dp[N][N][N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string s; cin >> s; n = s.size(); cin >> k;
    for (int i = 1; i <= n; ++i) dp[i][i][0] = 1;
    for (int len = 2; len <= n; ++len) 
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            for (int u = 0; u <= k; ++u) dp[l][r][u] = max(dp[l + 1][r][u], dp[l][r - 1][u]);
            if (s[l - 1] == s[r - 1]) for (int u = 0; u <= k; ++u) dp[l][r][u] = max(dp[l][r][u], dp[l + 1][r - 1][u] + 2);
            else for (int u = 1; u <= k; ++u) dp[l][r][u] = max(dp[l][r][u], dp[l + 1][r - 1][u - 1] + 2);
            //for (int u = 0; u <= k; ++u) cout << l << ' ' << r << ' ' << u << " : " << dp[l][r][u] << '\n';
        }   
    int ans = 0;
    for (int i = 0; i < N; ++i) ans = max(ans, dp[1][n][i]);
    cout << ans << '\n';
}