#include<bits/stdc++.h>
using namespace std;
int n,a,b,f[5005];
long long dp[5005];
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        f[x]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int pos=f[i];
        long long t=1e18;
        for(int j=1;j<=n;j++)
        {
            t=min(t,dp[j]);
            if(pos==j) dp[j]=t;
            else if(pos>j) dp[j]=t+b;
            else dp[j]=t+a;
        }
    }
    long long ans=1e18;
    for(int i=1;i<=n;i++)
        ans=min(ans,dp[i]);
    printf("%lld\n",ans);
}
/*dp[i][j]表示将第i个数搬移到前j个位置的最小价值*/
