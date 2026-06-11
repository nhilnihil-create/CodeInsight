#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> prob(n+1);
    for(int i = 1; i <= n; i++)
        cin >> prob[i];
    vector<vector<double>> dp(n+1, vector<double>(n+1)); 
    dp[0][0] = 1.000000000;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++)
            if(j == 0)
                dp[i][j] = (1.000000000 - prob[i]) * dp[i-1][j];
            else
                dp[i][j] = (prob[i] * dp[i-1][j-1]) + ((1.000000000 - prob[i])*dp[i-1][j]);
    cout << fixed << setprecision(10) << accumulate(dp[n].begin()+(n/2)+1, dp[n].end(), 0.0);
    return 0;
}
