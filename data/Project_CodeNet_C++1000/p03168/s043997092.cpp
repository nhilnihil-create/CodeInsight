#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define s(x, n) memset(x, n, sizeof(x));
#define pb(x) push_back(x)
#define NIL -1
#define MIN 1e-9
#define MAXN 3001
#define double long double

double dp[MAXN][MAXN];
double arr[MAXN];
double p(int n)
{
    s(dp, (double)0.0);
    dp[0][0] = (double)1.0;
    for (int i = 1; i <= n; i += 1)
    {
        for (int j = 0; j <= i; j += 1)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] * ((double)1.0 - arr[i]);
            else
                dp[i][j] = dp[i - 1][j] * ((double)1.0 - arr[i]) + dp[i - 1][j - 1] * arr[i];
        }
    }
    double ans = 0.0;
    for (int i = (n + 1) / 2; i <= n; i += 1)
        ans += dp[n][i];

    return ans;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    double ans = p(n);
    cout << fixed << setprecision(10);
    cout << ans << "\n";
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