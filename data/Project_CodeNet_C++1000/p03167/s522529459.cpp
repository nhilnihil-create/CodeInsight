#include <bits/stdc++.h>
using namespace std;
#define maxn 200004
#define MOD 1000000007
int H, W;
int main()
{
    cin >> H >> W;
    char board[H][W];
    long long int dp[H][W];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < W; i++)
    {
        if (board[0][i] != '#')
        {
            dp[0][i] = 1;
        }
        else
        {
            break;
        }
    }
    for (int i = 1; i < H; i++)
    {
        if (board[i][0] != '#')
        {
            dp[i][0] = 1;
        }
        else
        {
            break;
        }
    }
    for (int i = 1; i < H; i++)
    {
        for (int j = 1; j < W; j++)
        {
            if (board[i][j] != '#')
            {
                if (board[i - 1][j] != '#')
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j] + MOD) % MOD;
                }
                if (board[i][j - 1] != '#')
                {
                    dp[i][j] = (dp[i][j - 1] + dp[i][j] + MOD) % MOD;
                }
            }
        }
    }
    cout << dp[H - 1][W - 1];
    return 0;
}