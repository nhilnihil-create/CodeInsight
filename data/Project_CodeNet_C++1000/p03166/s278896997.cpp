#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100001];
int dp[100001];
int lenof(int src)
{
    bool leaf=1;
    if(dp[src]!=-1)
    {
        return dp[src];
    }
    int bestchild=0;
    for(auto child:graph[src])
    {
        leaf=0;
        bestchild=max(bestchild,lenof(child));

    }
    return dp[src]=leaf?0:1+bestchild;
}
int main() {
    memset(dp,-1,sizeof(dp));
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {   int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,lenof(i));
    }
    cout<<ans;
}
