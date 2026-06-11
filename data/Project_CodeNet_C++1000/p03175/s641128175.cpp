#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 2*acos(0.0)
#define f first
#define s second
#define pb push_back
#define gap ' '
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define mod 1000000007
#define N 100005
int n;
vector<int> g[N];
ll dp[N][3];
ll solve(int u,int p,int t)
{
    if(dp[u][t]!=-1) return dp[u][t];
    dp[u][t]=1;
    if(t==0)
    {
        for(int v : g[u])
        {
            if(v==p) continue;
            dp[u][t]=(dp[u][t]*(solve(v,u,0)+solve(v,u,1))%mod)%mod;
        }
    }
    else{
        for(int v : g[u])
        {
            if(v==p) continue;
            dp[u][t]=(dp[u][t]*solve(v,u,0))%mod;
        }
    }
    return dp[u][t]%mod;
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    memset(dp,-1,sizeof dp);
    cout<<(solve(1,-1,0)+solve(1,-1,1))%mod<<endl;
}
