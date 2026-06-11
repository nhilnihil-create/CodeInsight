#include<bits/stdc++.h>
using namespace std;
#define int long long int 
vector<vector<int>> g;
int d_time[55];
int a_time[55];
int visited[55];
int ans;
int t;
void bridge(int src,int parent)
{
    visited[src]=true;
    d_time[src]=a_time[src]=++t;
    for(auto i:g[src])
    {
        if(i!=parent && visited[i]==1)
        a_time[src]=min(a_time[src],d_time[i]);
        else if(i!=parent)
        {
            bridge(i,src);
            a_time[src]=min(a_time[src],a_time[i]);
            if(a_time[i]>d_time[src])
            ans++;
        }
    }


}
int32_t main()
{
    int m,n;
    cin>>n>>m;
    ans=0;
    t=0;
    memset(d_time,0,sizeof(d_time));
    memset(a_time,0,sizeof(a_time));
    memset(visited,0,sizeof(visited));
    g=vector<vector<int>>(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    if(!visited[i])
    bridge(i,-1);
    cout<<ans<<endl;
}