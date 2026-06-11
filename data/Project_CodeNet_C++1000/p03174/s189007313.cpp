#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3e3 + 5, inf = INT_MAX, mod = 1e9 + 7;

int n, dp[22][(1 << 22)], a[22][22];

int solve(int i, int mask)
{
    if (i == n)
        return 1;
    if (dp[i][mask] != -1)
        return dp[i][mask];
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[i][j] == 1 && ((1 << j) & mask) == 0)
            ans = (ans + solve(i + 1, ((1 << j) | mask))) % mod;
    }
    return dp[i][mask] = ans;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    cout << solve(0, 0);
    return 0;
}