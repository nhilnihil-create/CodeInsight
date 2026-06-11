/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
std::vector<long long> adj[100007];
long long dp[100007];
bool vis[100007];
long long dfs(long long x)
{
    long long ans=0;
    long long val=0;
    vis[x]=true;
    if(dp[x]!=-1){return dp[x];}
    for(auto itr:adj[x])
    {
        ans=0;
        if(!vis[itr]){ans+=dfs(itr)+1;}
        else{ans=dp[itr]+1;}
        val=max(val,ans);
    }
    dp[x]=val;
    return val;
}

int main()
{
    long long bro=0,vv,n,m,i,x,y;
    cin>>n>>m;
    for(i=0;i<=n;i++){dp[i]=-1;vis[i]=false;}
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i]){vv=dfs(i);bro=max(bro,vv);}
    }
    cout<<bro;
    return 0;
}
