#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int n;
vector<int> adj[100005];
int dp[100005][2];

int solve(int u,bool constraint,int parent){

	if(dp[u][constraint]!=-1)
		return dp[u][constraint];

	int ans = 0;
	int w1 = 1;
	for(auto child: adj[u]){
		if(child!=parent)
			w1 = (w1*solve(child,0,u))%mod;
	}
	ans+=w1;

	int w2=1;
	if(!constraint){
		for(auto child: adj[u]){
		if(child!=parent)
			w2 = (w2*solve(child,1,u))%mod;
	}
		ans = (ans+w2)%mod;
	}



	return dp[u][constraint]=ans;


}



int32_t main(){
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
	cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	memset(dp,-1,sizeof dp);

	cout<<solve(1,0,-1)<<endl;






}