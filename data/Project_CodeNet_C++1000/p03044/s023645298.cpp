#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll level[100005];
vector<pair<ll int,ll int>>adj[100005];
void dfs(ll int child,ll int par,ll int dis)
{
    level[child]=level[par]+dis;
    for(auto x:adj[child])
    {
        if(x.first==par) continue;
        dfs(x.first,child,x.second);
    }
}
int main()
{
    long long int i,j,k,z,t,x,y,n;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    dfs(1LL,0LL,0LL);
    for(i=1;i<=n;i++)
    {
        if(level[i]%2==0)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}