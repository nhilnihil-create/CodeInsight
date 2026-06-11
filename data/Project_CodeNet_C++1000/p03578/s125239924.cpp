#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int N, M;
	cin >> N;
	vector<long long> D( N );
	for( int i = 0; i < N; i++ ) {
		cin >> D[i];
	}
	cin >> M;
	vector<long long> T( M );
	for( int i = 0; i < M; i++ ) {
		cin >> T[i];
	}

	sort( D.begin(), D.end() );
	sort( T.begin(), T.end() );
	string ans = "YES";
	int j = 0;
	for( int i = 0; i < M; i++ ) {
		int flag = 0;
		while( j < N ) {
			if( D[j] == T[i] ) {
				flag = 1;
				j++;
				break;
			}
			if( D[j] > T[i] ) break;
			j++;
		}
		if( flag == 0 ) {
			ans = "NO";
			break;
		}
	}

	cout << ans << endl;
}
