#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> P( N );
	for( int i = 0; i < N; i++ ) {
		cin >> P[i];
		P[i]--;
	}

	vector<int> Q( N );
	for( int i = 0; i < N; i++ ) {
		Q[ P[i] ] = i;
	}

	int k = 0;
	int kmax = 1;
	for( int i = 0; i < N - 1; i++ ) {
		if( Q[i] < Q[i + 1] ) {
			if( k ) k++;
			else k = 2;
		}
		else k = 0;
		kmax = max( kmax, k );
	}
	int ans = N - kmax;

	cout << ans << endl;
}
