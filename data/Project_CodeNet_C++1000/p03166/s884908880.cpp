#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void dfs(int src,vector<vector<int>>& g, vector<int>& vis, vector<int>& dp )
{
    vis[src]=1;
   
    if(g.size()==0)
    {
        dp[src]=1;
        return;
    }
    // cout<<src<<" "<<cs<<endl;
    for(int i=0;i<g[src].size();i++)
    {
        
        if(vis[g[src][i]]==0)
        {
            dfs(g[src][i],g,vis,dp);
        }
         if(g[src].size()!=0)
        {
            dp[src]=max(dp[src],1+dp[g[src][i]]);
            // return;
        }
        
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    // vector<int> vis(n,0);
    vector<vector<int>> a(m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[i].push_back(x-1);
        a[i].push_back(y-1);
    }
    vector<vector<int>> ad(n);
    for(int i=0;i<m;i++)
    {
        ad[a[i][0]].push_back(a[i][1]);
    }
    vector<int> vis(n,0);
    vector<int> dp(n,0);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,ad,vis,dp);
        }
    }
    // cout<<*max_element(dp.begin(),dp.end())<<endl;
    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;

    

}