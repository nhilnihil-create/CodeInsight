#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, T, A;
	cin >> N >> T >> A;
	vector<int> H( N );
	for( int i = 0; i < N; i++ ) {
		cin >> H[i];
	}

	T *= 1000;
	A *= 1000;
	int mi = INT32_MAX / 2;
	int ans;
	for( int i = 0; i < N; i++ ) {
		int t = T - H[i] * 6;
		if( abs( A - t ) < mi ) {
			mi = abs( A - t );
			ans = i + 1;
		}
	}

	cout << ans << endl;
}
