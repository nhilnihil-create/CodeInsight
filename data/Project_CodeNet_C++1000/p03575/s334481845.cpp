#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define inf 1000000000
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define meM(y,a) memset(y,a,sizeof y)
#define sC(a) scanf("%d",&a)
#define alL(a) a.begin(),a.end()
#define prinT(a,sz)  cout<<a[0];for(int i=1;i<sz;i++)cout<<" "<<a[i];cout<<endl
#define ranD srand(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int>pi;
typedef pair<ll,ll>pll;
//int fx[]={0,0,1,-1};
//int fy[]={1,-1,0,0};
//int gx[]={0,0,1,1,1,-1,-1,-1};
//int gy[]={1,-1,0,1,-1,0,1,-1};
const int N=100010;
int vis[N],low[N],dis[N];
int bd=0;
vector<int>adj[N];
int t=0;
void dfs(int node,int par)
{
//    cout<<node<<" vis "<<par<<endl;
    low[node]=dis[node]=++t;
    for(int i=0;i<adj[node].size();i++)
    {
        int chi=adj[node][i];
        if(chi==par)continue;
        if(dis[chi]==0){
            dfs(chi,node);
            low[node]=min(low[node],low[chi]);
        }
        else low[node]=min(low[node],dis[chi]);
        if(dis[node]<low[chi]){
            bd++;
//            cout<<node<<" here "<<chi<<endl;
        }
    }
}
int main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    cout<<bd<<endl;
}
/*
7 7
1 3
3 4
4 5
4 6
5 6
6 7
2 7

*/





