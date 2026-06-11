#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e18;
int dp[1 << 16];
int sum[1 << 16];
int a[16][16];
int n;

int getbit(int x, int i)
{
    return (x >> i) & 1;
}

void opti(int &a, int b)
{
    if (a < b) a = b;
}

int solve(int cur)
{
    int &res = dp[cur];
    if (!cur) return 0;
    if (res != -oo) return res;
    for (int sub = cur; sub > 0; sub = (sub - 1) & cur)
    {
        opti(res, solve(cur - sub) + sum[sub]);
    }
    return res;
}

signed main()
{
    //freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
        cin >> a[i][j];
    }
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        for (int k = j + 1; k < n; k++)
        {
            if (getbit(i, j) && getbit(i, k)) sum[i] += a[j][k];
        }
        dp[i] = -oo;
    }
    cout << solve((1 << n) - 1);
    return 0;
}
