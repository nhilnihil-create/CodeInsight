#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[100005];
vector<int> gr[100005];
int solve(int src)
{

if(dp[src]!=-1)
{
    return dp[src];
}
bool leaf=1;
int bestchild=0;
for(auto nbr:gr[src])
{  leaf=0;
    bestchild=max(bestchild,solve(nbr));
}

return dp[src]=(leaf?0:1+bestchild);
}
int main() {
    int n,m;
    cin>>n>>m;

    memset(dp,-1,sizeof(dp));
     for(int i=0;i<m;i++)
     {  int x,y;
         cin>>x>>y;
         x--;
         y--;
         gr[x].push_back(y);
     }
     int ans=0;
     for(int i=0;i<n;i++)
     {
         ans=max(ans,solve(i));
         
     }
     cout<<ans;
}
