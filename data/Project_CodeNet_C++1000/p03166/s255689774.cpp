#include <iostream>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long int,long long int>,null_type,less<pair<long long int,long long int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

vector<int> adj[100001];
int v[100001];
int dp[100001];

void dfs(int node)
{
    v[node]=1;
    for(int i=0;i<adj[node].size();i++)
    {
        if(!v[adj[node][i]])
            dfs(adj[node][i]);
    }
    for(int i=0;i<adj[node].size();i++)
        dp[node]=max(dp[node],1+dp[adj[node][i]]);
}
void go()
{
    int n,m;
    cin>>n>>m;
    memset(v,0,sizeof(v));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++)
    {
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
    }
    for(int i=1;i<=n;i++)
    {
        if(!v[i])
            dfs(i);
    }
    cout<<*max_element(dp,dp+100001);
}
int main()
{
    FIO;
//    int t;
//    cin>>t;
//    while(t--)
        go();
    return 0;
}

