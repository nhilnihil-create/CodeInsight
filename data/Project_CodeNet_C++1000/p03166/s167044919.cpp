#include<iostream>
#include<vector>
int n,m;
using namespace std;
void toposort(int s,vector<int> graph[],vector<bool> &visited,vector<int> &o)
{
    visited[s]=1;
    for(int v:graph[s])  
    {
        if(!visited[v])
        {
            toposort(v,graph,visited,o);
        }
    }
    o.push_back(s);
}
int main()
{
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    vector<int> o;
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            toposort(i,graph,visited,o);
        }
    }
    // for(int x:o)
    // cout<<x<<" "; 
    int best=0;
    vector<int> dp(n+1);
    for(int i=0;i<o.size();i++)
    {   
        for(int j=0;j<graph[o[i]].size();j++)
        {
            dp[o[i]]=max(dp[o[i]],dp[graph[o[i]][j]]+1);
            best=max(dp[o[i]],best);
        }
    }
    cout<<best;
}