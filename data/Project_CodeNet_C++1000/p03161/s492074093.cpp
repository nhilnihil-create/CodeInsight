#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define s(x, n) memset(x, n, sizeof(x));
#define pb(x) push_back(x)
#define NIL -1
#define MAXN 11

void solve()
{
    int n, k;
    //int cost=0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dp[n]; //, mn[n];
    s(dp, 0);
    //s(mn, 0);
    for (int j = 0; j < k; j++)
    {
        dp[0] = 0;
        dp[1] = abs(a[1] - a[0]);
    }
    //smn[1] = dp[1];
    for (int i = 2; i < n; i++)
    {
        int ans = INT_MAX;
        for (int j = 0; j < k; j++)
        {
            if (i - (j + 1) >= 0)
            {
                ans = min(ans, dp[i - j - 1] + abs(a[i] - a[i - j - 1]));
            }
        }
        dp[i] = ans;
    }
    cout << dp[n - 1] << "\n";
}
int main()
{
#ifdef WIN32
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef WIN32
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int t;
    t = 1;
    /// cin >> t;
    for (int I = 1; I <= t; I++)
    {
        solve();
    }
    return 0;
}