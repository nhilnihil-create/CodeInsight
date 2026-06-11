#include <bits/stdc++.h>
using namespace std;
#define ld long double
int n;
int main() {
    cin>>n;
    double p[n];
    for(int i=0;i<n;i++)
    cin>>p[i];
    double dp[2][2][n+1];
    memset(dp,0,sizeof dp);
    dp[0][0][1] = p[0];
    dp[0][1][0] = (1-p[0]);
    int flag=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(!k)
                {
                    dp[flag][k][j+1] = p[i]*(dp[1-flag][k][j]+dp[1-flag][1-k][j]);
                }
                else
                {
                    dp[flag][k][j] = (1-p[i])*(dp[1-flag][k][j]+dp[1-flag][1-k][j]);
                }
            }
        }
        flag = 1-flag;
    }
    ld ans=0.0;
    for(int i=n/2+1;i<=n;i++)
    {
        for(int k=0;k<2;k++)
        {
            ans+=dp[1-flag][k][i];
        }
    }
    cout<<fixed<<setprecision(10)<<ans;
}
