#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	long long ans = 0;
	for( int i = 0; i < N; i++ ) {
		if( i == 0 ) {
			if( A[i] != 0 ) {
				ans = -1;
				break;
			}
		}
		else {
			if( A[i] > A[i - 1] + 1 ) {
				ans = -1;
				break;
			}
		}
	}
	if( ans == 0 ) {
		for( int i = 0; i < N; i++ ) {
			if( i == 0 ) continue;
			else {
				if( A[i] == A[i - 1] + 1 ) ans++;
				else ans += A[i];
			}
		}
	}

	cout << ans << endl;
}
