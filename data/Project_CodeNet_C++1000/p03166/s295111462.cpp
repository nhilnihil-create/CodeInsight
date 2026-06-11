//Krunal_Mathukiya
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
#define pb push_back
#define mkp make_pair
#define nikalL return
#define chalavo continue
#define basHo break
#define umap unordered_map
#define fr(i,s,n) for(int i=s;i<=n;++i)
#define frr(i,s,n) for(int i=s;i>=n;--i)
#define jaldiKarNe ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
int n,m;
vector<int> g[100001];
int dp[100001];
int vis[100001];
void fn(int node) {
	vis[node]=1;
	dp[node]=0;
	for(auto child:g[node]) {
		if(!vis[child]) fn(child);
		dp[node]=max(dp[node],1+dp[child]);
	}
}
void TestingChaluKarEyy(){
	cin>>n>>m;
	fr(i,1,m) {
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
	}
	fr(i,1,n) {
		if(!vis[i]) fn(i);
	}
	int ans=0;
	fr(i,1,n) ans=max(ans,dp[i]);
	cout<<ans;
}
int main(){
//	#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	#endif
	jaldiKarNe;
	int TestingKaravvuChhe=1;
	// cin>>TestingKaravvuChhe;
	while(TestingKaravvuChhe--){
		TestingChaluKarEyy();
	}
}