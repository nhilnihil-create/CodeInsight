#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int,int>>adj[100005];
bool flag=true;
int col[300001],vis[300005];

void dfs(int u,int p,int c)
{
    col[u]=c;
    // cout<<u<<" "<<c<<endl;
    vis[u]=1;
    for(auto v:adj[u])
    {
        int x=v.first;
        int y=v.second;
        if(x==p) continue;
        dfs(x,u,(c+y)%2);


    }

}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,-1,0);


    for(int i=1; i<=n; i++)
        cout<<col[i]<<endl;
    return 0;

}
/*
ll dfs(ll node,ll c)
{
    vis[node]=1;
    col[node]=c;
    for(ll child:ar[node])
    {
        if(vis[child]==0)
        {
            ll code=dfs(child,c^1);
            if(code==-1)
            {
                return -1;
            }
        }
        else
        {
            if(col[child]==col[node])return -1;
        }
    }
    return 0;
}
*/
