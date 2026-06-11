// BWOTSHEWCHB

#include <bits/stdc++.h>

using namespace std ;

#define int long long
#define pb push_back
#define in insert
#define X first
#define Y second

const int MAXN = 1e6 + 69 , MOD = 1e9 + 7 ;

int n , leaf , dp[MAXN] , height[MAXN] ;
vector <int> g[MAXN] ;

void dfs(int v , int par = -1) {
	for ( auto u : g[v] )
		if ( u != par ) {
			height[u] = height[v] + 1 ;
			if ( height[u] > height[leaf] )
				leaf = u ;
			dfs(u , v) ;
		}
}

int32_t main() {
	ios::sync_with_stdio(false) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n ;
	int v , u ;
	for ( int i = 1 ; i < n ; i ++ )
		cin >> v >> u , g[v].pb(u) , g[u].pb(v) ;
	dp[0] = 0 , dp[1] = 1 ;
	for ( int i = 2 ; i <= n ; i ++ )
		dp[i] = (dp[i - 1] | dp[i - 2]) ^ 1 ;
	dfs(1) , memset(height , 0 , sizeof height) , dfs(leaf) ;
	if ( dp[height[leaf]] )
		cout << "Second\n" ;
	else
		cout << "First\n" ;
}
