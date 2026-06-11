#include <bits/stdc++.h>
using namespace std;

const int mxN = 21, mxV = 1 << 21, MOD = 1e9 + 7;
long long n, grid[mxN][mxN], dp[21][mxV];

long long recurse(int i, int mask)
{
    if (i < 0)
        return 1;
    if (dp[i][mask] != -1)
        return dp[i][mask];

    long long ways = 0;
    for (int j = 0; j < n; j++)
    {
        if (grid[i][j] == 1 && ((mask & (1 << j)) > 0))
        {
            int tmp = mask ^ (1 << j);
            ways += recurse(i - 1, tmp);
            ways %= MOD;
        }
    }
    dp[i][mask] = ways;
    return ways;
}

int main()
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < mxV; j++)
        {
            dp[i][j] = -1;
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << recurse(n - 1, (1 << n) - 1);
}