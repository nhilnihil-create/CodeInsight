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
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];

    int dp[n][3];
    s(dp, 0);
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    // cout << dp[0][0] << " " << dp[0][1] << " " << dp[0][2] << "\n";
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + b[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
        //   cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << "\n";
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