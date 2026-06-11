//sol->//https://www.geeksforgeeks.org/longest-path-in-a-directed-acyclic-graph-dynamic-programming/

#include <bits/stdc++.h>
using namespace std;
#define N 1000000007
vector<long>adj[100000];
vector<long>dp;
map<long,bool>vis;
vector<long>s;

void dfs(long v){
vis[v]=true;
for(auto x:adj[v]){if(!vis[x])dfs(x);    dp[v]=max(dp[v],dp[x]+1);   }


s.push_back(v);
}

int main() {
    long n,m;
    long x,y;
    cin>>n>>m;
    dp.assign(n,0);   //we need longest path so take wight of each here -1 and default as int_min
    for(long i=0;i<m;i++){cin>>x>>y; adj[x-1].push_back(y-1);}
    for(long i=0;i<n;i++){
        if(!vis[i])dfs(i);
    }
    
    long ans=LONG_MIN;
    for(long i=0;i<n;i++)ans=max(ans,dp[i]);
    cout<<ans<<endl;



	return 0;
}
