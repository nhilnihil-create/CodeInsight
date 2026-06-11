#include <bits/stdc++.h>
using namespace std;

int n;
int vals[4];
double dp[301][301][301];

double recurse(int i, int j, int k)
{
    if (abs(dp[i][j][k] + 1) > 1e-9)
        return dp[i][j][k];
    
    double ret = 0;
    ret += (double)n / (double)(i + j + k);

    if (i > 0)
        ret += (double)i / (double)(i + j + k) * recurse(i - 1, j, k);
    if (j > 0)
        ret += (double)j / (double)(i + j + k) * recurse(i + 1, j - 1, k);
    if (k > 0)
        ret += (double)k / (double)(i + j + k) * recurse(i, j + 1, k - 1);
    dp[i][j][k] = ret;

    return ret;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vals[x]++;
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;

    //printf() recurse(vals[1], vals[2], vals[3]) << endl;
    printf("%.10lf\n", recurse(vals[1], vals[2], vals[3]));
}