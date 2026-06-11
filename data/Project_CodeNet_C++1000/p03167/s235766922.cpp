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
    ll h, w;
    cin >> h >> w;
    string s[h];
    for (ll i = 0; i < h; i++)
        cin >> s[i];
    ll dp[h][w];
    s(dp, 0);
    dp[0][0] = 1;
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
                dp[i][j] = 0;
            else
            {
                if (i - 1 >= 0)
                {
                    dp[i][j] += (dp[i - 1][j] % mod);
                    dp[i][j] %= mod;
                }
                if (j - 1 >= 0)
                {
                    dp[i][j] += (dp[i][j - 1] % mod);
                    dp[i][j] %= mod;
                }
            }
        }
    }
    cout << dp[h - 1][w - 1] << "\n";
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