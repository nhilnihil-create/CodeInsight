#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;

    ll n = s.length(), m = t.length();
    ll dp[n + 1][m + 1];
    string b = "";
    ll i = -1, j = -1;
    for (ll x = 0; x <= n; x++)
    {
        for (ll y = 0; y <= m; y++)
        {
            if (x == 0 || y == 0)
                dp[x][y] = 0;
            else if (s[x - 1] == t[y - 1])
            {
                dp[x][y] = 1 + dp[x - 1][y - 1];
            }
            else
                dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]);
        }
    }
    //cout << i << " " << j << "\n";
    i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            b = s[i - 1] + b, i--, j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    cout << b << "\n";
}