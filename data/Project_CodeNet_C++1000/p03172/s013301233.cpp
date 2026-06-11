//thuanqvbn03
#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100005;
const int Mod = 1000000007;

int n, k;
int a[105];
int dp[105][MaxN], ps[105][MaxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= k; i++)
    {
        ps[0][i] = 1;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        ps[i][0] = 1;
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = (ps[i - 1][j] - (j > a[i] ? ps[i - 1][j - a[i] - 1] : 0) + Mod) % Mod;
            ps[i][j] = (ps[i][j - 1] + dp[i][j]) % Mod;
        }
    }
    cout << dp[n][k];
    return 0;
}