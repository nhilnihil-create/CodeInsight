#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> dp;

int dfs(int v){
	if(dp[v]!=-1)
		return dp[v];
	dp[v]=1;
	for(auto c: adj[v]){
		dp[v]=max(dp[v],1+dfs(c));
	}
	return dp[v];
}
int main(){
	int n,m,res=0;
	cin >> n >> m;
	adj=vector<vector<int>>(n+1);
	dp=vector<int>(n+1,-1);
	for(int i=0;i<m;i++){
		int s,d;
		cin >> s >> d;
		adj[s].push_back(d);
	}
	for(int i=1;i<=n;i++){
		if(dp[i]==-1){
			res=max(res,dfs(i));
		}
	}
	if(res > 0)
		res-=1;
	cout<<res<<"\n";
}