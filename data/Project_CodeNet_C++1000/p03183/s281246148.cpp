//thuanqvbn03
#include <bits/stdc++.h>

using namespace std;

struct Block
{
    int w, s, v;
    bool operator<(const Block data) const
    {
        return (w + s != data.w + data.s ? w + s < data.w + data.s : s < data.s);
    }
};

int n;
Block a[1005];
long long dp[1005][20005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].w >> a[i].s >> a[i].v;
    }
    sort(a + 1, a + n + 1);
    int m = a[n].s * 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i].w && j - a[i].w <= a[i].s)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].w] + a[i].v);
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = max(ans, dp[n][i]);
    }
    cout << ans;
    return 0;
}