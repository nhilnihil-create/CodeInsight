#include <bits/stdc++.h>
using namespace std;
int main()
{
    int H, W;
    cin >> H >> W;
    int dp[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> dp[i][j];
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            int A;
            cin >> A;
            if (A == -1)
            {
                continue;
            }
            ans += dp[A][1];
        }
    }
    cout << ans << endl;
}