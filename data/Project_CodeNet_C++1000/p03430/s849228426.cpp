/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 302;

int n;

string s;

int k;

int dp[N_MAX][N_MAX][N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.size();
    s = " " + s;
    cin >> k;
    for(int l = 0; l <= n; l++)
        for(int r = n + 1; r >= l; r--)
            if(l >= 1 || r <= n)
            {
                for(int c = 0; c <= k; c++)
                {
                    if(l >= 1)
                        dp[l][r][c] = max(dp[l][r][c], dp[l - 1][r][c]);
                    if(r <= n)
                        dp[l][r][c] = max(dp[l][r][c], dp[l][r + 1][c]);
                    if(c >= 1)
                        dp[l][r][c] = max(dp[l][r][c], dp[l][r][c - 1]);
                    if(l >= 1 && r <= n)
                    {
                        if(s[l] == s[r])
                            dp[l][r][c] = max(dp[l][r][c], dp[l - 1][r + 1][c] + 1 + (l < r));
                        else if(c >= 1)
                            dp[l][r][c] = max(dp[l][r][c], dp[l - 1][r + 1][c - 1] + 1 + (l < r));
                    }
                }
            }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i][i][k]);
    cout << ans << "\n";
    return 0;
}
