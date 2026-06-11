#include <bits/stdc++.h>
using namespace std;

#define N 100000*2
#define INF 1LL << 60

long long n, X;
long long sum[N+1];

int main()
{
	cin >> n >> X;
	for( long long i = 0; i < n; i++ ) {
		long long x;
		cin >> x;
		sum[i + 1] = sum[i] + x;
	}

	long long ans = INF;
	for( long long k = 1; k <= n; k++ ) {
		long long i = n;
		long long res = (n + k) * X + sum[i] * 5;
		i -= k * 2;
		while( i > 0 ) {
			res += sum[i] * 2;
			i -= k;
			if( res < 0 ) {	// avoid overflow
				res = INF;
				break;
			}
		}
		ans = min( ans, res );
	}

	cout << ans << endl;

	return 0;
}
