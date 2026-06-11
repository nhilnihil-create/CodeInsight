#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define p pair<ll,ll>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define pi acos(-1)
const int mx=1e5+7;
vector<p>adj[mx];
vector<ll> vis(mx),dis(mx);
 queue<ll> q;
void bfs(ll s)
{

    q.push(s);
    vis[s]=1;
    dis[s]=0;
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(auto i:adj[u])
        {
            if(!vis[i.ff])
            {
                q.push(i.ff);
                vis[i.ff]=1;
                dis[i.ff]=dis[u]+i.ss;
            }
        }
    }
}
//for a tree
int main()
{
    fast;
    ll n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    bfs(1);
    for(int i=1;i<=n;i++)
    {
       // cout<<dis[i]<<" ";
        cout<<(dis[i]&1?1:0)<<endl;
    }
}
