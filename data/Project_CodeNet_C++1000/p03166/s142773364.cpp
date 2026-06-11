#include <bits/stdc++.h> 
using namespace std;
#define int long long int
#define float double
#define pb push_back
#define FF first
#define SS second
#define N 100005
#define MOD 1000000007
#define fn(i,n) for(int i=0;i<n;i++)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pii pair<int,int>
#define mp make_pair
#define INF 9223372036854775807
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n,m;
vector<int> adj[N];
int dp[N];
int ans=0;

int dfs(int node)
{
    if(dp[node]!=-1) return dp[node];
    dp[node]=0;
    for(auto child:adj[node]) dp[node]=max(dfs(child)+1,dp[node]);
    ans=max(ans,dp[node]);
    return dp[node];
}


signed main() 
{
    speed;
    //freopen("input.tXt","r",stdin);
    //freopen("output.tXt","w",stdout);

    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    fn(i,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }

    for(int i=1;i<=n;i++)
    {
        if(dp[i]==-1) dfs(i);
    }
    cout<<ans<<endl;
}   