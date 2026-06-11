#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	long long X;
	cin >> N >> X;
	vector<long long> x( N );
	for( int i = 0; i < N; i++ ) {
		cin >> x[i];
	}

	long long ans = abs( x[0] - X );
	for( int i = 1; i < N; i++ ) {
		ans = __gcd( ans, abs(x[i] - X) );
	}

	cout << ans << endl;
}
