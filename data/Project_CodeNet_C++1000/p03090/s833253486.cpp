#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int _w;

int n;
set<pii> st;

int main() {
	cin >> n;
	for( int i = 1; i <= n; ++i )
		for( int j = i+1; j <= n; ++j )
			st.insert( pii(i, j) );
	int L, R;
	if( n & 1 ) {
		L = 1, R = n-1;
	} else {
		L = 1, R = n;
	}
	while( L < R ) {
		st.erase( pii(L, R) );
		++L, --R;
	}
	printf( "%d\n", (int)st.size() );
	for( pii edge : st )
		printf( "%d %d\n", edge.first, edge.second );
	return 0;
}
