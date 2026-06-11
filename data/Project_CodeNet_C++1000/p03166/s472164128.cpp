#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int dp[100007];
int dfs(vector<vector<int>>&adj, int s){

	if(dp[s]!=-1) return dp[s];
	if(adj[s].size()==0) {
		dp[s]=0;
		return 0;
	}
	int height=0;
	for(int i: adj[s]){

			height = max(height,dfs(adj, i));

	}

	dp[s]= height+1;
	return height+1;
	
}
int main(){
	memset(dp, -1, sizeof(dp));
	int n, m;
	cin>>n>>m;
	n; m;
	vector<vector<int>>adj(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		adj[x].push_back(y);
	}

	int ans= 0;
	for(int i=0;i<n;i++){

			ans= max(ans, dfs(adj, i));

	}
	cout<<ans<<endl;
	return 0;
	
	
}
