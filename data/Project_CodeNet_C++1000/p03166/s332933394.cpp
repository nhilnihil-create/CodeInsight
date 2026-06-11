#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define hell 1000000007
#define PI 3.14159265358979323846
#include <fstream>
using namespace std;
vector<ll> adj[100005];
ll vis[100005];
stack<ll> st;
void dfs(ll x)
{
    vis[x]=1;
    for(ll i=0;i<adj[x].size();i++)
        if(!vis[adj[x][i]])
        dfs(adj[x][i]);
    st.push(x);
}
int main()
{
    //  freopen("timber_input.txt", "r", stdin);
   // freopen("out3_test.txt", "w", stdout);
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
   // cin>>t;
    while(t--) {
    ll n,m,i,j;
    cin>>n>>m;
    ll x,y;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
    }
    for(i=1;i<=n;i++)
        vis[i]=0;
     ll dis[n+5];
    for(i=1;i<=n;i++)
        dis[i]=0;
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);

    }
    while(!st.empty())
        {
            x=st.top();
            st.pop();
         //   cout<<x<<"\n";
            for(j=0;j<adj[x].size();j++)
                if(dis[adj[x][j]]<dis[x]+1)
                dis[adj[x][j]]=dis[x]+1;
        }
    ll ans=0;
    for(i=1;i<=n;i++)
    ans=max(ans,dis[i]);
    cout<<ans;

    }

}
