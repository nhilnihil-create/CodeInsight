#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define int long long

void dfs(int i,vector<int> adj[],vector<bool> &vis,int dp[]){
	//cout<<i<<"-";
	vis[i]=1;
	
	for(int j=0;j<adj[i].size();j++){
		int node=adj[i][j];
		if(!vis[node])
		dfs(node,adj,vis,dp);
		
		dp[i]=max(dp[i],1+dp[node]) ;
	}
}


signed main(){


#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#else
// online submission
#endif


int n,e;
cin >> n >> e;

vector<int> adj[n+1];

for(int i=0;i<e;i++){
	int a,b;
	cin >> a >> b;
	adj[a].push_back(b) ;
}


vector<bool> vis(n+1,false);
int dp[n+1]={0};

for(int i=1;i<=n;i++){
	if(!vis[i])
	dfs(i,adj,vis,dp);
}

int ans=INT_MIN;
for(int i=1;i<=n;i++)
ans=max(ans,dp[i]);

cout<<ans;
    
	
	return 0;
    
}


