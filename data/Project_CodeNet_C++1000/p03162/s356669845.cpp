#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 2;
int n, points[mxN][3], dp[mxN][3];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            int ret = -1;
            for (int t = 0; t < 3; t++)
            {
                if (t == j)
                    continue;
                ret = max(ret, points[i][t] + dp[i + 1][t]);
            }
            dp[i][j] = ret;
        }
    }

    cout << max({points[0][0] + dp[1][0], points[0][1] + dp[1][1], points[0][2] + dp[1][2]});
}