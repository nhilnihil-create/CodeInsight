#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	long double ans = 0;
	for( int n = 1; n <= N; n++ ) {
		long double t = 1.0 / N;
		int i = n;
		while( i < K ) {
			i *= 2;
			t /= 2;
		}
		ans += t;
	}

	cout << fixed << setprecision(12) << ans << endl;
}
