#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N;
	cin >> N;

	long long ans = 0;
	set<long long> st;
	for( long long n = 1; n * n < N; n++ ) {
		long long mul = N - n;
		if( mul % n == 0 ) {
			long long m = mul / n;
			if( st.count( m ) == 0 && N / m == N % m ) {
				ans += m;
				st.insert( m );
			}
		}
	}

	cout << ans << endl;
}
