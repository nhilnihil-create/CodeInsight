#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<double> > dp(n+1,vector<double> (n+1));
    vector<double>  a(n+1);
    for(int i=1;i<=n;i++)
    cin>>a[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j]*(1-a[i])+dp[i-1][j-1]*a[i];
        }
    }
    double sum=0;
    for(int i=(n+1)/2;i<=n;i++)
    {
        sum+=dp[n][i];
    }
    printf("%.10lf",sum);
}