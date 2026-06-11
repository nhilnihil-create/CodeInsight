#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mod = 1e9+7;
const ll nax = 1e5+7;

ll n,dp[nax][2]={{0}};
bool vis[nax]={0};
vector<ll> edge[nax];

void DFS(ll s,ll par = -1){
	vis[s]=true;
	
	bool value=false;
	
	for (auto it: edge[s]){
		if (it!= par) {
			DFS(it,s);
			
			dp[s][0]=dp[s][0]*(dp[it][0]+dp[it][1])%mod;
			dp[s][1]=dp[s][1]*dp[it][0]%mod;
		}
	}
}

int main(){
//	freopen("input.inp","r",stdin);
//	freopen("output.out","w",stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	
	for (ll i=0;i<=n;++i) dp[i][0]=dp[i][1]=1;
	
	for (ll i=0;i<n-1;++i){
		ll a,b;
		cin>>a>>b;
		
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	DFS(1);
	
	cout<<(dp[1][0]+dp[1][1])%mod<<"\n";
	
}