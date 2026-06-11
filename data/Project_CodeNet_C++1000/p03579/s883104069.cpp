///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100005;
int n,m;
vector<int>adj[M];
int vis[M];
int flag=0;
int b=0,w=0;
void dfs(int u,int par)
{
    if(flag)return ;
    if(!par)
    {
        vis[u]=1;
        w++;
    }
    else
    {
        if(vis[par]==1)vis[u]=2,b++;
        else vis[u]=1,w++;
    }
    for(auto v:adj[u])
    {
        if(v==par)continue;
        if(vis[v]==0)
        {
            dfs(v,u);
        }
        else if(vis[v]==vis[u])
        {
            flag=1;
        }
    }
}
 main()

{
    fast
    cin>>n>>m;
    f(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    if(flag)
    {
        int x=n*(n-1);
        x=x/2;
        x-=m;
        cout<<x<<endl;
        return 0;
    }
   cout<<(b*w)-m<<endl;
    return 0;

}

































