#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> C( N );
	vector<int> S( N );
	vector<int> F( N );
	for( int i = 0; i < N - 1; i++ ) {
		cin >> C[i] >> S[i] >> F[i];
	}

	for( int i = 0; i < N; i++ ) {
		long long ans = 0;
		if( i == N - 1 ) cout << ans << endl;
		else {
			for( int j = i; j < N; j++ ) {
				if( j == N - 1 ) {
					cout << ans << endl;
					break;
				}
				else {
					if( ans <= S[j] ) ans += S[j] - ans;
					else {
						int m = ans % F[j];
						if( m ) ans += F[j] - m;
					}
					ans += C[j];
				}
			}
		}
	}
}
