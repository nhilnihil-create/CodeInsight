#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int N;
	cin >> N;
	vector<int> h( N );
	for( int i = 0; i < N; i++ ) {
		cin >> h[i];
	}

	int ans = 0;
	while( 1 ) {
		int l = -1;
		int r = -1;
		for( int i = 0; i < N; i++ ) {
			if( h[i] > 0 ) {
				l = i;
				break;
			}
		}
		if( l < 0 ) break;
		for( int i =  l + 1; i < N; i++ ) {
			if( h[i] == 0 ) {
				r = i;
				break;
			}
		}
		if( r < 0 ) r = N;
		const int INF = 101;
		int mi = INF;
		for( int i =  l; i < r; i++ ) {
			if( mi > h[i] ) mi = h[i];
		}
		for( int i =  l; i < r; i++ ) {
			h[i] -= mi;
		}
		ans += mi;
	}

	cout << ans << endl;
}
