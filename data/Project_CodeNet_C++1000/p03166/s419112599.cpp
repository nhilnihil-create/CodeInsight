#include<bits/stdc++.h>
using namespace std ;

/*                        [Template]                        */
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) x.find( y ) != x.end()
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
int mod = (int)1e9 + 7 ;
/************************************************************/

class Graph{
	public :
		int nodes ;
		vector<vector<int>> g ;
		Graph( ){
			nodes = 0 ;
		}
		Graph( int nodes ) : nodes ( nodes ) {
			g.resize( nodes + 1 ) ;
		}
		void init( int nodes ){
			this -> nodes = nodes ;
			g.resize( nodes + 1 ) ;
		}
		void refresh(){
			g.clear() ;
			nodes = 0 ;
		}
		void addEdge( int &f, int &t ){
			g[f].push_back(t) ;
		}
} ;

Graph G ;
vector<int> dist ;

int max( int itr, vector<bool> &vis ){
	if( dist[itr] != -1 ) return dist[itr] ;
	vis[itr] = true ;
	int mx = 0 ;
	for( int v : G.g[itr] ){
		// if( !vis[v] )
		mx = max( mx, max( v, vis ) ) ;
	}
	return dist[ itr ] = ( mx + 1 ) ;
}

signed main(){
	int N, M ; cin >> N >> M ;
	int f, t ;
	G.init( N ) ;
	dist.resize( N + 1 ) ;
	dist.assign( N + 1, -1 ) ;
	for( int e = 1 ; e <= M ; e++ ){
		cin >> f >> t ;
		G.addEdge( f, t ) ;
	}
	vector<bool> vis( N + 1, false ) ;
	for( int i = 1 ; i <= N ; i++ ){
		if( !vis[i] ){
			max( i, vis ) ;
		}
	}
	G.refresh() ;
	int ans = 0 ;
	// for( int d of dist ) cout << d << " " ; cout << endl ;
	for( int d of dist ) ans = max( ans, d - 1 ) ;
	cout << ans ;
	return 0 ;
}