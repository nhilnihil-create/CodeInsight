#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> visited;
vector<ll> tour;
void dfs(ll s,vector<vector<ll> > &graph)
{
    visited[s]=true;
    tour.push_back(s+1);
    for(ll i=0;i<4;i++)
    {
        if(graph[s][i] && !visited[i])
        {dfs(i,graph);tour.push_back(s+1);}
    }
}
int main()
{
    vector<vector<ll> > graph(4,vector<ll> (4,0));
    ll a,b;
    visited.resize(4,false);
    for(ll i=0;i<3;i++)
    {
        cin>>a>>b;
        graph[a-1][b-1]=1;
        graph[b-1][a-1]=1;
    }
    dfs(0,graph);
    ll sum = 0;
    for(ll i=0;i<4;i++)
    {
        sum+=tour[i];
    }
    /*for(ll i=0;i<7;i++)
    cout<<tour[i];
    cout<<"\n";*/
    if(sum == 10)
    cout<<"YES";
    else
    cout<<"NO";
    return 0;
}