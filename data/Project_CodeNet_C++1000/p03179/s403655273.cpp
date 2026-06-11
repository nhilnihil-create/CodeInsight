//thuanqvbn03
#include <bits/stdc++.h>

using namespace std;

const int MaxN = 3005;
const long long Mod = 1000000007;

int n;
string s;
long long dp[MaxN][MaxN], ps[MaxN][MaxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            ps[i - 1][j] = (ps[i - 1][j - 1] + dp[i - 1][j]) % Mod;
        }
        if (s[i - 2] == '<')
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i][j] = ps[i - 1][j - 1];
            }
        }
        else
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i][j] = (ps[i - 1][i - 1] - ps[i - 1][j - 1] + Mod) % Mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + dp[n][i]) % Mod;
    }
    cout << ans;
    return 0;
}