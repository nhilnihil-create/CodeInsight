#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>> &G,vector<bool> &vis,vector<int> &dp){
	vis[node]=true;
  	dp[node]=0;
  	for(int child:G[node]){
     	if(!vis[child])
          	dfs(child,G,vis,dp);
      	dp[node]=std::max(dp[node],dp[child]+1);
    }
}

int main(){
    int N,M;
    cin>>N>>M;
  	vector<vector<int>> G(N+1);
  	while(M--){
    	int a,b;
      	cin>>a>>b;
      	G[a].push_back(b);
    }
  	vector<bool> vis(N+1,false);
	vector<int> dp(N+1);
  	for(int i=1;i<=N;i++){
    	if(!vis[i]){
        	dfs(i,G,vis,dp);
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}