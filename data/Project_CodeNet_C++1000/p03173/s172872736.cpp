#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18L +5;
int main()
{
    int n;
    cin>>n;
    vector<long long int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<vector<long long int>>dp(n+1,vector<long long int>(n+1,INF));
    for(int l=n-1;l>=0;l--)
    {
        for(int r=l;r<n;r++)
        {
            if(l==r)dp[l][r]=0;
            else
            {
                long long int sum=0;
                for(int i=l;i<=r;i++)
                {
                    sum=sum+a[i];
                }
                for(int i=l;i<r;i++)
                {
                    dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+sum);
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}