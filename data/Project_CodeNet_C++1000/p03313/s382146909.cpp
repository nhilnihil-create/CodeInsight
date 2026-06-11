#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=19;
int n,a[1<<N],ans[1<<N];
pair<int,int>dp[1<<18];
unordered_map<int,int>vis;
int main()
{
    scanf("%d",&n);
    int up=1<<n;
    for(int i=0;i<up;i++)
        scanf("%d",&a[i]);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<up;i++)
    {
        for(int j=0;j<n;j++)
        if(i>>j&1)
        {
            int st=i^(1<<j);
            if(dp[st].fi!=dp[i].fi&&dp[st].fi!=dp[i].se)
            {
                if(a[dp[st].fi]>a[dp[i].fi])
                    dp[i].se=dp[i].fi,dp[i].fi=dp[st].fi;
                else if(a[dp[st].fi]>a[dp[i].se])
                    dp[i].se=dp[st].fi;
            }
            if(dp[st].se!=dp[i].fi&&dp[st].se!=dp[i].se)
            {
                if(a[dp[st].se]>a[dp[i].fi])
                    dp[i].se=dp[i].fi,dp[i].fi=dp[st].se;
                else if(a[dp[st].se]>a[dp[i].se])
                    dp[i].se=dp[st].se;
            }
        }
        if(a[i]>a[dp[i].fi])
            dp[i].se=dp[i].fi,dp[i].fi=i;
        else if(a[i]>a[dp[i].se])
            dp[i].se=i;
    }
    int mx=0;
    for(int i=1;i<up;i++)
    {
        int s=0;
        if(dp[i].fi!=-1) s+=a[dp[i].fi];
        if(dp[i].se!=-1) s+=a[dp[i].se];
        mx=max(mx,s);
        printf("%d\n",mx);
    }
}
