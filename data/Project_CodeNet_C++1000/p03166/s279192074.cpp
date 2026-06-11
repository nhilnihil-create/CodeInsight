#include <bits/stdc++.h>
#ifdef LOCAL
#include <pprint.hpp>
#endif
#define endl "\n";
#define pb push_back
#define md 1000000007
#define ll long long int
#define all(v) v.begin(),v.end()
ll power(ll a,ll b){ll z=1;while(b){if(b&1){z*=a;z%=md;}a*=a;a%=md;b/=2;}return z%md;}
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n,m,u,v;
vector<ll> used;
vector<vector<ll>> adj;

ll dfs(ll s){
	// cout<<s<<endl;
	if(used[s])
		return used[s];
	ll val=0;
	for(auto x:adj[s])
	{
		val = max(val,(ll)dfs(x));
	}
	used[s] = 1+val;
	return used[s];
}

int main(){
	//You need to change array size!
	#ifndef LOCAL
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	#endif 
	
	cin>>n>>m;
	adj.resize(n+1);
	used.assign(n+1,0);
	for(int i=0;i<m;++i){
		cin>>u>>v;
		adj[u].pb(v);
		// adj[v].pb(u);
	}

	for(int i=1;i<=n;++i)
		dfs(i);
	// cout<<used<<endl;
	cout<<*max_element(all(used))-1;
	
	return 0;	
}