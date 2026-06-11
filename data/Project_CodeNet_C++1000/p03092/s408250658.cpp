#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=s;i<t;i++)
typedef long long ll;
const ll inf=1e18;
ll dp[2][5555];int num[5555];
int main()
{
    int n,a,b;scanf("%d%d%d",&n,&a,&b);
    rep(i,1,n+1)scanf("%d",&num[i]);
    rep(i,1,n+1)dp[0][i]=inf;
    int type=1;dp[0][0]=0;
    rep(i,1,n+1)
    {
        rep(i,0,n+1)dp[type][i]=1e18;
        rep(j, 0, n+1)if(dp[!type][j]!=inf)
        {
            if(num[i]<j)dp[type][j]=min(dp[type][j],dp[!type][j]+b);
            else dp[type][j]=min(dp[type][j],dp[!type][j]+a),dp[type][num[i]]=min(dp[type][num[i]],dp[!type][j]);
        }
        type=!type;
    }
    ll res=inf;
    rep(i,1,n+1)res=min(res,dp[!type][i]);
    printf("%lld\n",res);
}