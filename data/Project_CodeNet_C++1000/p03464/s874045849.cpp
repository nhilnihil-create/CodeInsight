#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int K;
	cin >> K;
	vector<long long> A( K );
	for( int i = 0; i < K; i++ ) {
		cin >> A[i];
	}

	auto f = [&]( long long n ) -> long long
	{
		long long res = n;
		for( int i = 0; i < K; i++ ) {
			res -= res % A[i];
			if( res < 0 ) return -1;
		}
		return res;
	};

	const long long INF = INT64_MAX / 2;
	long long l = 0;
	long long r = INF;
	while( r - l > 1 ) {
		long long m = (l + r) / 2;
		if( f( m ) <= 2 ) l = m;
		else r = m;
	}
	long long ma = l;
	l = 0;
	r = INF;
	while( r - l > 1 ) {
		long long m = (l + r) / 2;
		if( f( m ) >= 2 ) r = m;
		else l = m;
	}
	long long mi = r;

	if( mi > ma ) cout << -1 << endl;
	else cout << mi << " " << ma << endl;
}
