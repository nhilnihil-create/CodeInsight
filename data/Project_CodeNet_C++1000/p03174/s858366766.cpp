//thuanqvbn03
#include <bits/stdc++.h>

using namespace std;

const int Mod = 1000000007;

int n;
int a[21][21];
int dp[21][1 << 21];

int GetBit(int num, int pos)
{
    return (num >> pos) & 1;
}

int Cal(int i, int Bitmask)
{
    if (i == n)
    {
        return 1;
    }
    if (dp[i][Bitmask] != -1)
    {
        return dp[i][Bitmask];
    }
    dp[i][Bitmask] = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[i][j] && GetBit(Bitmask, j) == 0)
        {
            dp[i][Bitmask] = (dp[i][Bitmask] + Cal(i + 1, Bitmask | (1 << j))) % Mod;
        }
    }
    return dp[i][Bitmask];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        for (int j = (1 << 21) - 1; j >= 0; j--)
        {
            dp[i][j] = -1;
        }
    }
    cout << Cal(0, 0);
    return 0;
}