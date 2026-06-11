#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e9

//precalculate vertices with indegree 0 and outdegree 0;
//our answer path starts from one of them
//dp[i] longest path from dp[i]--> dp[i] = 1 + dp[v],v is s.t. {i-v edges}
vector<int> adj[100000];
vector<int> ind;
vector<int> out;
vector<int> dp;
int v,e;
int top(int i){
	if(out[i]==0) return dp[i] = 0;
	if(dp[i]==-1){
		for(int j:adj[i]){
			dp[i] = max(dp[i],top(j)+1);
		}
	} 
	return dp[i];
}

int main(){
	cin>>v>>e;
	// adj = vector<vector<bool> >(v,vector<bool>(v,0));
	ind = vector<int>(v,0);
	out = vector<int>(v,0);
	dp = vector<int>(v,-1);
	for(int i=0;i<e;i++){
		int a,b;cin>>a>>b;
		adj[a-1].push_back(b-1);
		ind[b-1]++;
		out[a-1]++;
	}
	int ans=0;
	for(int i=0;i<v;i++){
		if(ind[i]==0){
			ans = max(ans,top(i));
		}
	}
	// for(int i=0;i<v;i++) cout<<dp[i]<<endl;
	cout<<ans<<endl;
	return 0;
}