#include<bits/stdc++.h>
using namespace std;
int n;
vector<double> p;
vector<vector<double>> dp;


void solve()
{
    dp.resize(n+1, vector<double>(n+1,0.0));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        dp[0][i] = (1-p[i])*dp[0][i-1];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[j][i] = p[i]*dp[j-1][i-1] + (1-p[i])*dp[j][i-1];
        }
    }
    double res = 0.0;
    int m = n/2+1;
    for(int i=m; i<=n; i++){
        res += dp[i][n];
    }
    cout << setprecision(9) << res << '\n';
}

int main()
{
    cin >> n;
    p.resize(n+1);
    for(int i=1; i<=n; i++) cin >> p[i];
    solve();
    return 0;   
}