#include <bits/stdc++.h>

using namespace std;
const int N = 200010;
const int MOD = 1e9+7;
int _w;

int n, c[N], f[N], last[N];

int main() {
	_w = scanf( "%d", &n );
	for( int i = 1; i <= n; ++i )
		_w = scanf( "%d", c+i );
	f[1] = 1, last[c[1]] = 1;
	for( int i = 2; i <= n; ++i ) {
		if( last[c[i]] ) {
			f[i] = (f[i] + f[last[c[i]]]) % MOD;
		}
		if( last[c[i]] != i-1 ) {
			f[i] = (f[i] + f[i-1]) % MOD;
		}
		// printf( "f[%d] = %d\n", i, f[i] );
		last[c[i]] = i;
	}
	cout << f[n] << endl;
	return 0;
}
