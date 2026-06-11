#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> L( M );
	vector<int> R( M );
	for( int i = 0; i < M; i++ ) {
		cin >> L[i] >> R[i];
		L[i]--;
		R[i]--;
	}

	vector<int> v( N + 1 );
	for( int i = 0; i < M; i++ ) {
		v[ L[i] ]++;
		v[ R[i] + 1 ]--;
	}
	for( int i = 0; i < N; i++ ) {
		v[i + 1] += v[i];
	}
	int ans = 0;
	for( int i = 0; i < N + 1; i++ ) {
		if( v[i] == M ) ans++;
	}

	cout << ans << endl;
}
