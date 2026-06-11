//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define int ll

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

int const N = 1e5 + 20 ;
int n , d[N] , sz[N] ;
map <int , int> mp ;
vector <int> g[N] ;
vector <pii> edges ;

void err () {
	cout << -1 << '\n' ;
	exit(0) ;
}

int sum = 0 ;
void dfs (int v , int h = 0) {
	sum += h ;
	for (int u : g[v]) dfs(u , h + 1) ;
}

int32_t main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;

	for (int i = 0 ; i < n ; i ++) cin >> d[i] , mp[d[i]] = i , sz[i] = 1 ;

	sort(d , d + n , greater<int>()) ;

	for (int i = 0 ; i < n - 1 ; i ++) {
		int v = mp[d[i]] ;
		int k = d[i] - n + 2 * sz[v] ;

		if (k >= d[i] || !mp.count(k)) err() ;

		int p = mp[k] ;

		sz[p] += sz[v] ;
		edges.push_back({p , v}) ;
	
		g[p].push_back(v) ;
	}

	dfs(mp[d[n - 1]]) ;

	if (d[n - 1] != sum) err() ;

	for (pii p : edges) cout << p.F + 1 << ' ' << p.S + 1 << '\n' ;
}
