#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
#define sf(x) scanf("%d",&x)
#define sfl(x) scanf("%lld",&x)
#define lli long long int
#define ll64 int64_t
#define pb push_back
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define frr(i,a) for(int i=0;i<a;i++)
#define frl(i,a) for(lli i=0;i<a;i++)
const lli mx=100001;
vector<pii>adj[mx];
bool vis[mx];
lli clr[mx];
void dfs(lli sn,lli dis)
{
    vis[sn]=true;
    for(lli i=0;i<adj[sn].size();i++)
    {
        lli d=adj[sn][i].first;
        lli v=adj[sn][i].second;
        if((dis+d)%2==0)
        {
            clr[v]=1;
        }

        if(!vis[v])
        {
            dfs(v,dis+d);
        }
    }
    return ;
}
int main()
{
    lli n,u,v,w;
    cin>>n;
    for(lli i=0;i<n-1;i++)
    {
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].pb({w,v});
        adj[v].pb({w,u});
    }
    memset(clr,0,sizeof(clr));
    memset(vis,false,sizeof(vis));
    clr[0]=1;
    dfs(0,0);
    for(lli i=0;i<n;i++)
    {
        cout<<clr[i]<<endl;
    }
}
