#include<bits/stdc++.h>
using namespace std;
int maxLevel;
vector<int> dp;
int dfs(int i,vector<vector<int>> &graph,vector<bool> &vis){
    if(dp[i]!=-1)return dp[i];
    vis[i]=true;
    dp[i]=0;
    for(int node:graph[i]){
        
            dp[i]= max(dp[i],dfs(node,graph,vis)+1);
        
    }
    return dp[i];
    
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n);
    dp.clear();
    dp.resize(n,-1);
    int a,b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        a--,b--;
        graph[a].push_back(b);
    }
    vector<bool> vis(n);
    maxLevel=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            maxLevel=max(maxLevel,dfs(i,graph,vis));
        }
    }
    cout<<maxLevel<<endl;
}