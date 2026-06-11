#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int N;
	string S;
	cin >> N >> S;

	vector<int> bv( N );
	vector<int> wv( N );
	int w = 0;
	int b = 0;
	for( int i = 0; i < N; i++ ) {
		bv[i] = b;
		if( S[i] == '#' ) b++;
	}
	for( int i = N - 1; i >= 0; i-- ) {
		wv[i] = w;
		if( S[i] == '.' ) w++;
	}
	int ans = N;
	for( int i = 0; i < N; i++ ) {
		ans = min( ans, bv[i] + wv[i] );
	}

	cout << ans << endl;
}
