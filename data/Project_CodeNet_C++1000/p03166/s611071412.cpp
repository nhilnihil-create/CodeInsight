
// Problem : G - Longest Path
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_g
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// It's something that is not good
// & i'm trying right just nothing
// dont't know what god is upto
// but i shall tryna make it come.
#include "bits/stdc++.h"
using namespace std;
using ll=long long;
#define el "\n"
ll dp[2000000];
void dfs(vector<ll> graph[],ll start,vector<ll> &visit,ll &ans){
	visit[start]=1;
	
	for(auto child:graph[start]){
		//dp[child]=max(dp[child],dp[start]+1);
		
		if(!visit[child]){
			//dp[child]=dp[start]+1;
		 dfs(graph,child,visit,ans);
		// cout<<"HERE"<<endl;
		 }
		
	}
	for(auto child:graph[start]){
	 	dp[start]=max(dp[start],dp[child]+1);
	 	ans=max(ans,dp[start]);
	 	}
}
ll tests=1;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   // cin>>tests;
    while(tests--){
        ll n; cin>>n; ll m; cin>>m;
        vector<ll> graph[n];
        for(int i=0;i<m;i++){
        	ll x,y; cin>>x>>y; --x; --y;
        	graph[x].push_back(y);
        	//graph[y].push_back(x);
        }
        vector<ll> visit(n,0);
        ll ans=-INT_MAX;
        for(int i=0;i<n;i++){
        	if(!visit[i]){
        		dp[i]=0;
        	 dfs(graph,i,visit,ans);
        	 }
        }
        
       // for(int i=0;i<n;i++) ans=max(ans,dp[i]);
        cout<<ans<<el;
        
    }
}