#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define mod 1000000007

const int sz=4e2+5;
ll inf=1e15;

ll dp[sz][sz],ar[sz],n,pre[sz];

ll f(int st,int en)
{
    if(st==en)
        return 0;
    if(en-st==1)
        return ar[st]+ar[en];
    ll &res=dp[st][en];
    if(res!=-1)
        return res;
    res=inf;
    for(int k=st;k<en;k++)
    {
        res=min(res,pre[k]-pre[st-1]+f(st,k)+pre[en]-pre[k]+f(k+1,en));
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n;

        for(int i=1;i<=n;i++)
        {
            cin>>ar[i];
            pre[i]+=ar[i]+pre[i-1];
        }

        memset(dp,-1,sizeof(dp));

        cout<<f(1,n);

        
    }

    return 0;
}