#include <bits/stdc++.h>
using namespace std;
const int N = 3005;
double dp[N][N];

int main()
{
    int n;
    cin >> n;
    vector<double> p;
    for(int i = 0; i < n; ++i)
    {
        double a;
        cin >> a;
        p.push_back(a);
    }
    dp[0][0] = 1.0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j]*(1 - p[i-1]);
            }
            else
            {
                dp[i][j] = dp[i-1][j-1]*p[i-1] + dp[i-1][j]*(1 - p[i-1]);
            }
        }
    }
    // for(int i = 0; i <= n; i++)
    //     for(int j = 0; j <= n; ++j)
    //         cout << dp[i][j] << " \n"[j == n];
    

    double ans = 0;
    for(int j = n; j > n/2; --j)
    {
        ans += dp[n][j];
    }
    cout << fixed << setprecision(10) << ans;
}