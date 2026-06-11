#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}
	typedef pair<int, int> P;
	vector<P> BC( M );
	for( int i = 0; i < M; i++ ) {
		cin >> BC[i].second >> BC[i].first;
	}

	sort( A.begin(), A.end() );
	sort( BC.begin(), BC.end(), greater<P>() );
	vector<int> D;
	for( int i = 0; i < M; i++ ) {
		int C = BC[i].first;
		int B = BC[i].second;
		for( int j = 0; j < B; j++ ) {
			if( A[D.size()] > C ) break;
			D.push_back( C );
			if( D.size() >= N ) break;
		}
		if( D.size() >= N ) break;
	}
	long long ans = 0;
	for( int i = 0; i < D.size(); i++ ) {
		ans += D[i];
	}
	for( int i = D.size(); i < N; i++ ) {
		ans += A[i];
	}

	cout << ans << endl;
}
