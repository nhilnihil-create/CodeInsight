#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

int dp[1 << 21];
int a[100][100];
int n;

void add(int &a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
}

int getbit(int x, int i)
{
    return (x >> i) & 1;
}

int solve(int i, int cur)
{
    int &res = dp[cur];
    if (i == n) return 1;
    if (res != -1) return res;
    res = 0;
    for (int j = 0; j < n; j++)
    {
        if (!getbit(cur, j) && a[i][j])
        {
            add(res, solve(i + 1, cur | (1 << j)));
        }
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
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
    return 0;
}
