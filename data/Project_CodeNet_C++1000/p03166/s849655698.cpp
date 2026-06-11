#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define vl vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
const int N=100005;
vector<int> edges[N];
int dis[N]{};
int vis[N]={};
int inDeg[N]{};
void dfs(int n)
{
    vis[n]=1;
    for(int b: edges[n])
    {
        dis[b]=max(dis[b],dis[n]+1);
        inDeg[b]--;
        if(inDeg[b]==0)
            dfs(b);
    }
}
void solve()
{
    int n,k=1,m=0,i=1,j,x,y,l,r,z;
    int ans=0,sum=0,value=0,weight;
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        edges[x].pb(y);
        inDeg[y]++;
    }
    for(i=1;i<=n;i++)
    {
        edges[0].pb(i);
        inDeg[i]++;
    }
    for(i=0;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
    }
    ans=*max_element(dis,dis+n+1);
    cout<<ans-1;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif 
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}