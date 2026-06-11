#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll n,m,x[200005],ob[200005];
vector<pair<ll,ll>> adj[200005];

void dfs(ll a)
{
    ob[a]=1;
    for(auto u: adj[a])
    {
        if(!ob[u.first])
        {
            x[u.first]=x[a]+u.second;
            dfs(u.first);
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,-w});
    }

    for(ll i=1;i<=n;i++)
        if(!ob[i])
        {
            x[i]=0;
            dfs(i);
        }
    ll ind=0;
    for(ll i=1;i<=n;i++)
        for(auto u: adj[i])
            if(x[u.first]-x[i]!=u.second)
            {
                ind=1;
                break;
            }


    if(!ind)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


    return 0;
}
