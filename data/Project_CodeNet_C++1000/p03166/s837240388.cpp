#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>> l;
int dp[100001];

int lp(int src)
{
    if(dp[src]!=-1)
        return dp[src];
    bool leaf=1;
    int ans=INT_MIN;
    for(auto it:l[src])
    {
        leaf=0;
        ans=max(ans,lp(it));
    }
    if(leaf==true)
        return dp[src]=0;
    return dp[src]=ans+1;
}


int main()
{
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        l[x].push_back(y);
    }
    int ans=0;
    for(int i=1; i<=n; i++)
        ans=max(ans,lp(i));
    cout<<ans;
}