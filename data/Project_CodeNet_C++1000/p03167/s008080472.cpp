#include <bits/stdc++.h>
using namespace std;

const int mxH = 1e3 + 2, MOD = 1e9 + 7;
int h, w, dp[mxH][mxH];
char grid[mxH][mxH];

int calc(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    return dp[i][j];
}

int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '#')
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                continue;
            }
            else
            {
                dp[i][j] = calc(i - 1, j) + calc(i, j - 1);
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;
}