#include<bits/stdc++.h>
using namespace std;
vector<int> visited;
vector<int> dp;
vector<vector<int> > adj;
vector<int> indegree;
void dfs(int s)
{
    visited[s]=1;
    for(auto it:adj[s])
    {
        indegree[it]--;
        dp[it]=max(dp[it],dp[s]+1);
        if(indegree[it]==0)
        {
            dfs(it);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1,0);
    indegree.resize(n+1,0);
    dp.resize(n+1,1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        indegree[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]&&indegree[i]==0)
        dfs(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans-1<<endl;
}