#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define maxim INT_MAX
#define fi first
#define se second
#define INF 1e16
/* 1. If you can't keep solution in mind, then visualize it on a paper.
 * 2. Try to identify the type of problem - DP, Greedy, Graph, Constructive,
 * 	  Prefix/Suffix, Difference Array, BIT/Segment Tree, etc.
 * 3. Look at the problems from different perspectives - reverse the problem,
 * 	  add instead of delete (maybe?)
 * 4. Divide difficult solutions into cases and/or sequences.
 * 5. Use math rules to solve Nested Summation.
 * 6. Optimisation problems are generally solved with DP, greedy, binary search or brute-force.
 * 7. Try fixing a solution then proving we can't do better or worse than that.
 * ------------------------------------------------------------------
 */
vector <ll> adj[100005];
ll dis[100005];
ll ans=0;
 void dfs(ll node)
{
    for(auto child:adj[node])
    {
        if(dis[child]==0)
            dfs(child);
        dis[node]=max(dis[node],1+dis[child]);
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector <ll> indeg(n+1,0);

    for(ll i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        indeg[v]++;
    }
    vector <ll> vertices;
    for(ll i=1;i<=n;i++)
    {
        if(indeg[i]==0)
            vertices.pb(i);
    }
    memset(dis,0,sizeof(dis));
    for(auto vertex:vertices)
    {
        dis[vertex]=0;
        dfs(vertex);
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
        ans=max(ans,dis[i]);
    cout<<ans<<endl;



}
