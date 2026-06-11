#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	long double d = N - (K - 1);
	long double ans = d / N;
	long double neg = 1.0 - ans;
	if( d < 0 ) {
		ans = 0;
		neg = 1;
	}
	int mi = min( N, K - 1 );
	for( int n = 1; n <= mi; n++ ) {
		long double t = (long double)K / n;
		long double p = ceil( log2( t ) );
		p = pow( 2, p );
		p *= mi;
		ans += 1 / p * neg;
	}

	cout << fixed << setprecision(12) << ans << endl;
}
