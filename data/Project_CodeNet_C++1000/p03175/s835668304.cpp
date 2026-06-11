#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define bitcnt(v) __builtin_popcount(v)
#define all(v) v.begin(), v.end()

int n, mod = 1e9 + 7;; 
vector<vector<int>> graph;
ll dp[100003][2];
// B -- W
// W -- B/W

// state only depends on which vertex we are at and whether its parent is colored black

ll solve(int u, int p, bool p_black){
	if(dp[u][p_black] != -1) return dp[u][p_black];
	ll ways_white = 1, ways_black = !p_black;
	for(int v : graph[u]){
		if(v == p) continue;
		ways_white *= solve(v,u,0);
		ways_white %= mod;
		if(!p_black){
			ways_black *= solve(v,u,1);
			ways_black %= mod;
		}
	}
	return dp[u][p_black] = (ways_black + ways_white) % mod;
}


void solution(){
	cin >> n;
	graph = vector<vector<int>>(n);
	for(int i = 0; i < n-1; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(dp,-1,sizeof(dp));
	cout << solve(0,-1,0) << endl;

}	


int main(){ 

	fio;
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solution();
	} 
	return 0;
}
