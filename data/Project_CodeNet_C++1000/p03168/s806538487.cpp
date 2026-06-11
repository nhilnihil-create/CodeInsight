#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e3 + 10;
int n;
double p[mxN], dp[mxN][2 * mxN + 10];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    dp[0][n + 1] = p[0];
    dp[0][n - 1] = 1 - p[0];
    for (int i = 1; i < n; i++)
    {
        for (int diff = -n; diff <= n; diff++)
        {
            dp[i][diff + n] = p[i] * dp[i - 1][n + diff - 1] + (1 - p[i]) * dp[i - 1][n + diff + 1];
        }
    }

    double ret = 0;
    for (int i = n + 1; i <= 2 * n; i++)
    {
        ret += dp[n - 1][i];
    }
    printf("%.10lf\n", ret);
}