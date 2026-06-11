#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100002];
int dp[100002];
int dfs(int src)
{
    int ans=0;

    if(dp[src]!=-1)
    {
        return dp[src];
    }
    for(int i=0;i<graph[src].size();i++)
    {
        int v=graph[src][i];
        ans=max(ans,dfs(v)+1);
    }
    return dp[src]=ans;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }

    int max_ans=0;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        max_ans=max(max_ans,dfs(i));
    }
    cout<<max_ans<<endl;
}
