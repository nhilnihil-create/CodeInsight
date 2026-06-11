#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;
#define rep( i, n, m ) for(int i = ( n ); i < ( m ); i++)
#define rep_d( i, n, m ) for(int i = ( n ) - 1; i >= ( m ); i--)
#define sort_asc( X ) sort(( X ).begin(), ( X ).end())
#define sort_desc( X ) sort(( X ).begin(), ( X ).end(), greater <>())

template <class T> bool chmax( T& a, T b );
template <class T> bool chmin( T& a, T b );
int* eratosthenes( int N );
bool bit_search( int pattern, int N );
template <class T> void cumulative_sum( T array, size_t N );

const ll INF = 1LL << 60;
const int k_mod = 1e9 + 7;

typedef struct {
	vector <int> to;
	int cost;
	bool is_visited;
} edge;
void recursive_comb( int*indexes, int s, int rest, std::function <void( int* )> f ) {
	if (rest == 0){
		f( indexes );
	}
	else {
		if (s < 0) return;
		recursive_comb( indexes, s - 1, rest, f );
		indexes[ rest - 1 ] = s;
		recursive_comb( indexes, s - 1, rest - 1, f );
	}
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb( int n, int k, std::function <void( int* )> f ) {
	int indexes[ k ];
	recursive_comb( indexes, n - 1, k, f );
}

int main( void ){
	int N, C; cin >> N >> C;
	vector <vector <int> > color( N, vector <int>( N )), cost( C, vector <int>( C ));
	rep( i, 0, C ) rep( j, 0, C ) cin >> cost[ i ][ j ];
	rep( i, 0, N ) rep( j, 0, N ) cin >> color[ i ][ j ];

	vector <vector <int> > cost_of_colors( 3, vector <int>( C, 0 ));
	rep( i, 0, N ){
		rep( j, 0, N ){
			int index = ( i + j ) % 3;
			rep( c, 0, C )
				cost_of_colors[ index ][ c ] += cost[ color[ i ][ j ] - 1 ][ c ];
		}
	}
	int min_cost = k_mod;
	foreach_comb( C, 3, [ cost_of_colors, &min_cost ]( int*indexes ) {
		vector<int> v{indexes[0],indexes[1],indexes[2]};
		do {
			int sum = 0;
			rep( i, 0, 3 )
				sum += cost_of_colors[ i ][ v[ i ] ];
			min_cost = min( min_cost, sum );
		} while (std::next_permutation( v.begin(), v.end()));
	} );
	cout << min_cost << endl;
}

int* eratosthenes( int N ){
	int* prime_array = new int[ N + 1 ];
	int lim = N;
	prime_array[ 0 ] = 0;
	prime_array[ 1 ] = 0;
	rep( i, 2, N + 1 ){
		prime_array[ i ] = 1;
	}
	rep( i, 2, lim ){
		if (prime_array[ i ] == 0)
			continue;
		lim = N / i;
		for(int j = i * 2; j < N + 1; j += i){
			prime_array[ j ] = 0;
		}
	}
	return prime_array;
}
template <class T> void cumulative_sum( T array, size_t N ) {
	rep( i, 1, N + 1 ){
		array[ i ] += array[ i - 1 ];
	}
}
template <class T> bool chmax( T& a, T b ) {
	if (a < b){
		a = b; return true;
	}
	return false;
}
template <class T> bool chmin( T& a, T b ) {
	if (a > b){
		a = b; return true;
	}
	return false;
}
bool bit_search( int pattern, int N ){
	int cnt = 0;
	rep( bit, 0, N ){
		if (pattern & ( 1 << bit )){
			cnt++;
		}
	}
	return true;
}
