#include<bits/stdc++.h>
using namespace std;
int m = 1e9+7;
/*long long cnt(int n, int k, vector<int>v,vector<vector<long long>>&dp)
{
    if(k==0)
    return 1;

    if(n==-1 && k!=0)
    return 0;

    if(dp[n][k]!=-1)
    return dp[n][k];

    if(v[n]>0)
    {
           long long a = (cnt(n-1,k,v,dp))%m;
           v[n]--;
           long long b = (cnt(n,k-1,v,dp))%m;
           dp[n][k] = (a+b)%m;
    }
    else
    {
        dp[n][k] = (cnt(n-1,k,v,dp))%m;
    }
    return ((dp[n][k])%m);
}
int main()
{
    int n,k;
    cin>>n>>k;

    vector<int>v(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<vector<long long>>dp(n,vector<long long>(k+1,-1));

    long long ans = cnt(n-1,k,v,dp);
    cout<<(ans%m)<<endl;
}
*/
int main()
{
    int n,k;
    cin>>n>>k;

    vector<int>v(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));

    dp[0][0]=1;
    for(int i=1;i<=k;i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0]= dp[i-1][0];
    }

    for(int i=1;i<=n;i++)
    {
        vector<int>sum(k+1);
        sum[0] = dp[i-1][0];
        for(int j=1;j<=k;j++)
        {
             sum[j] = (dp[i-1][j]+sum[j-1])%m;
        }
        for(int j=0;j<=k;j++)
        {
            if(j<=v[i])
            {
              dp[i][j] = sum[j];
            }
            else
            {
                int a = j-v[i]-1;
                dp[i][j] = (sum[j]-sum[a]+m)%m;
            }
        }
        sum.clear();
    }
    cout<<dp[n][k]<<endl;
}
