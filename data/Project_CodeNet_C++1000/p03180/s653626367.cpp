#include <bits/stdc++.h>
#define pb push_back
#define int long long int
#define mod 1000000007
#define inf (1LL<<60)
#define f(i,a,b) for (int i= a; i <b; ++i)
using namespace std;
int a[17][17];
int dp[(1<<16)];
int sum[(1<<16)];
int calculatesum(int n)
{
    for(int i=1;i<=((1<<n)-1);i++)
    {
        dp[i]=inf;
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if((i&(1<<j))!=0&&(i&(1<<k))!=0)
                    sum[i]+=a[j][k];
            }
        }
        //cout<<sum[i]<<" ";
    }
}
int solve(int mask)
{
   if(mask==0)
    return 0;
   if(dp[mask]!=inf)
     return dp[mask];
   int ans=0;
   for(int submask=mask;submask!=0;submask=(submask-1)&mask)
   {
       ans=max(ans,sum[submask]+solve(mask^submask));
   }
   return dp[mask]=ans;
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        cin>>a[i][j];
     calculatesum(n);
    cout<<solve((1<<n)-1);

}

