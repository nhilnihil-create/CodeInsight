#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define mex 100005
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<int> adj[mex];
//a+b=a^b+2*(a&b)
ll dp[mex];
ll dp1[mex];

void dfs(int v, int p){
	
	int q=0;
	for(auto u:adj[v]){
		if(u!=p){
		 q=1;
		 dfs(u,v);
	    }
	}
	if(q==0){
		dp[v]=1;
		dp1[v]=1;
	}
	else{
		ll x=1,y=1;
		for(auto u:adj[v]){
			if(u!=p){
				x=(x*dp1[u])%mod;
				y=(y*(dp[u]+dp1[u])%mod)%mod;
			}
		}
		dp[v]=x%mod;
		dp1[v]=y%mod;
	}
}

		
int main(){
	fast
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		 int x,y;
		 cin>>x>>y;
		 adj[x].push_back(y);
		 adj[y].push_back(x);
	}
	dfs(1,1);
	cout<<(dp[1]+dp1[1])%mod;
	 
}
