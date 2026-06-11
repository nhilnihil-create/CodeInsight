#include<bits/stdc++.h>
#define l long 
#define ll long long 
#define ld long double 
#define INF 1000000000000000
#define MOD 1000000007
#define MAX_N 100006
#define f first
#define s second
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULLL);
using namespace std;
vector<vector<l>> adj(MAX_N);
vector<ll> dp1(MAX_N),dp2(MAX_N);
vector<bool> vis(MAX_N,false);
void dfs_solver(l pos)
{
    vis[pos]=true;
    dp1[pos]=1;
    dp2[pos]=1;
    for(l i=0;i<adj[pos].size();i++)
    {
        if(!vis[adj[pos][i]])
        {
            dfs_solver(adj[pos][i]);
            dp1[pos]=(dp1[pos]*(dp1[adj[pos][i]]+dp2[adj[pos][i]]))%MOD;
            dp2[pos]=(dp2[pos]*dp1[adj[pos][i]])%MOD;
        }
    }
    return;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    l n,x,y;
    cin>>n;
    for(l i=0;i<n-1;i++)
    {
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs_solver(0L);
    ll ans=(dp1[0]+dp2[0])%MOD;
    if(ans<0)
    ans+=MOD;
    cout<<ans<<endl;
}