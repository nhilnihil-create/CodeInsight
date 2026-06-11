#include <bits/stdc++.h>
#define int long long
using namespace std;

#define mod 1000000007
#define pi 2 * acos(0.0)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
void fun()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

/* DON'T LIMIT YOUR CHALLENGES, CHALLENGE YOUR LIMITS */
void solve()
{
    int h, w;
    cin >> h >> w;

    vector<vector<char>> v(h, vector<char>(w));
    for (auto &i : v)
        for (auto &j : i)
            cin >> j;
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
    for (int i = 0; i < w; i++)
    {
        if (v[0][i] == '#')
            break;
        dp[1][i + 1] = 1;
    }

    for (int i = 0; i < h; i++)
    {
        if (v[i][0] == '#')
            break;
        dp[i + 1][1] = 1;
    }

    for (int i = 2; i <= h; i++)
    {
        for (int j = 2; j <= w; j++)
        {
            if (v[i - 1][j - 1] == '#')
                continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }

    // for (auto i : dp)
    // {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << "\n";
    // }

    cout << dp[h][w];
}

signed main()
{
    fun();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}