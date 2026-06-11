#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<string> S( N );
	for( int i = 0; i < N; i++ ) {
		cin >> S[i];
	}

	int ans = 0;
	for( int B = 0; B < N; B++ ) {
		vector<string> T( N, string( N, ' ' ) );
		for( int i = 0; i < N; i++ ) {
			for( int j = 0; j < N; j++ ) {
				T[i][j] = S[i][(j + B) % N];
			}
		}

		int flag = 0;
		for( int i = 0; i < N; i++ ) {
			for( int j = 0; j < N; j++ ) {
				if( T[i][j] != T[j][i] ) {
					flag = 1;
					break;
				}
			}
			if( flag ) break;
		}
		if( flag == 0 ) ans += N;
	}

	cout << ans << endl;
}
