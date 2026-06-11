#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[100005];
vector<int> grph[100005];
int vis[100005]={0};
int n,m;

int dfs(int a)
{
    if(dp[a]!=-1)
        return dp[a];
    if(vis[a]==0)
    {
        vis[a]=1;
        int ma=0;
        int &ans=dp[a];
        ans=0;
        for(auto &k:grph[a])
            ans=max(ans,dfs(k) + 1);
        return ans;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        int y;
        cin>>x>>y;
        grph[x].push_back(y);
    }
    int soln=0;
    for(int i=1;i<=n;i++)
        if(!vis[i])
            soln=max(soln,dfs(i));
    cout<<soln;
} 