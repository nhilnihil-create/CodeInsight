#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

int n;
const int N=100100,mod=1e9+7;
vector<int>g[N];
int dp[N][2]; // white, black

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n-1;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(dp,-1,sizeof(dp));
	function<int(int,int,int)> dfs=[&](int u,int c,int p){
		if(~dp[u][c])return dp[u][c];
		dp[u][c]=1;
		for(auto v:g[u])if(v!=p){
			ll dm=dfs(v,0,u)%mod;
			if(!c)dm=(dm+dfs(v,1,u))%mod;
			dp[u][c]=dp[u][c]*dm%mod;
		}
		return dp[u][c];
	};
	cout<<(dfs(0,0,0)+dfs(0,1,0))%mod<<endl;
}
