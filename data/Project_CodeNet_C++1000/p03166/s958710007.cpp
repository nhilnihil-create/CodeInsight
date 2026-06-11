#include<bits/stdc++.h>
#define mp make_pair
// #define pb push_back
#define ll long long
#define endl "\n"
using namespace std;

vector<vector<ll> > graph(100001);
ll dp[100001];


ll solve(ll i){
	if(graph[i].size()==0){
		return 0;
	}
	if(dp[i]!=-1){
		return dp[i];
	}
	vector<ll>::iterator it;
	dp[i]=0;
	ll ans=LLONG_MIN;
	for(it=graph[i].begin();it!=graph[i].end();it++){
		ans=max(ans,solve(*it));
	}
	dp[i]=ans+1;
	return dp[i];
}


int main() {
	ll n,m;
	cin>>n>>m;
	while(m--){
		ll x,y;
		cin>>x>>y;
		graph[x].push_back(y);
	}
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		if(dp[i]==-1){
			ll x=solve(i);
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
}