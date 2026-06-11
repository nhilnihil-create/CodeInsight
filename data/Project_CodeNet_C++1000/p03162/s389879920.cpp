#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> abc(n, vector<int>(3));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> abc[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(3));

    for(int i = 0; i < 3; i++)
    {
        dp[0][i] = abc[0][i];
    }

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + abc[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + abc[i][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + abc[i][2];
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

    return 0;
}