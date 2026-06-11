#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
ll mod=1e9+7;
pair<ll,ll> dfs(int s,vector<int> graph[],vector<bool> &visited)
{
    visited[s]=1;
    pair<ll,ll> pr={1,1};
    for(int v:graph[s])
    {
        if(!visited[v])
        {
            pair<ll,ll> pr1=dfs(v,graph,visited);
            pr.first*=pr1.second;
            pr.first%=mod;
            pr.second*=(pr1.second+pr1.first);
            pr.second%=mod;
        }
    }
    return pr;
}
int main()
{
    int n;
    cin>>n;
    vector<int> graph[n+1];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<bool> visited(n+1,false);
    pair<ll,ll> pr=dfs(1,graph,visited);
    cout<<(pr.first+pr.second)%mod;
}