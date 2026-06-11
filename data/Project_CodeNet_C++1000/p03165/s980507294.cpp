#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define s(x, n) memset(x, n, sizeof(x));
#define pb(x) push_back(x)
#define NIL -1
#define MAXN 3010

int dp[MAXN][MAXN];
int lcs(const string &a, const string &b, int n, int m)
{
    if (n >= a.size() || m >= b.size())
    {
        return 0;
    }
    if (dp[n][m] != -1)
        return dp[n][m];
    if (a[n] == b[m])
    {
        dp[n][m] = 1 + lcs(a, b, n + 1, m + 1);
    }
    else
    {
        dp[n][m] = max(lcs(a, b, n + 1, m), lcs(a, b, n, m + 1));
    }

    return dp[n][m];
}
void solve()
{
    s(dp, -1);
    string a, b;
    cin >> a >> b;
    int an = lcs(a, b, 0, 0);
    string ans = "";
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            ans += a[i];
            i++;
            j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
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
    // cin >> t;
    for (int I = 1; I <= t; I++)
    {
        solve();
    }
    return 0;
}