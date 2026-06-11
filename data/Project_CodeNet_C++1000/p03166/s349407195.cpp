#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vll vector<long long>
#define ll long long
#define pii pair<int,int>
const int mod=1e9+7;
int dfs(vector<int> adj[],int v,vector<int> &dp){
	if(adj[v].size()==0) return dp[v]=0;
	if(dp[v]!=-1) return dp[v];
	for(auto i:adj[v]){
		dp[v]=max(dp[v],dfs(adj,i,dp));
	}
	dp[v]++;
	return dp[v];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
#endif
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    int x,y;
    for(int i=0;i<m;i++){
    	cin>>x>>y;
    	x--;
    	y--;
    	adj[x].pb(y);
    }
    vector<int> dp(n,-1);
    int ans=0;
    for(int i=0;i<n;i++){
    	if(dp[i]==-1){
    		ans=max(ans,dfs(adj,i,dp));
    	} 
    }
    cout<<ans<<"\n";
    return 0;
}