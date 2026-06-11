#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[5005];
int dp[5005][5005];
int n,A,B;

int solve(int i, int maxx)
{
    if (i == n) return 0;
    if (dp[i][maxx] != -1) return dp[i][maxx];
    dp[i][maxx] = 0;
    if (a[i + 1] > maxx)
    {
        dp[i][maxx] = min(solve(i + 1, maxx) + A, solve(i + 1, a[i + 1]));
    } else {
        dp[i][maxx] = solve(i + 1, maxx) + B;
    }
    return dp[i][maxx];
}

signed main()
{
    //freopen("file.inp","r",stdin);
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = -1;
    cout << solve(0, 0);
    return 0;
}
