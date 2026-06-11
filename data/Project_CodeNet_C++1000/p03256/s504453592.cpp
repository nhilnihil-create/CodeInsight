//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

int const N = 2e5 + 20 ;
int n , m , A[N] , B[N] ;
bool mark[N] ;
string s ;
vector <int> g[N] ;
queue <int> que ;

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> m ;
	cin >> s ;
	for (int i = 0 , u , v ; i < m ; i ++) {
		cin >> u >> v ;
		u -- , v -- ;
		g[u].push_back(v) ;
		g[v].push_back(u) ;

		(s[u] == 'A' ? A[v] : B[v]) ++ ;
		(s[v] == 'A' ? A[u] : B[u]) ++ ;
	}

	for (int i = 0 ; i < n ; i ++) {
		if (!A[i] || !B[i]) mark[i] = 1 , que.push(i) ;
	}

	int cnt = 0 ;

	while (_sz(que)) {
		int v = que.front() ;
		que.pop() ;
		cnt ++ ;

		for (int u : g[v]) {
			(s[v] == 'A' ? A[u] : B[u]) -- ;
			if (!mark[u] && (!A[u] || !B[u])) mark[u] = 1 , que.push(u) ;
		}
	}

	cout << (cnt < n ? "Yes" : "No") << '\n' ;
}
