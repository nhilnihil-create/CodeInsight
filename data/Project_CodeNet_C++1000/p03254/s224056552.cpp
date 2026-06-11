#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	long long x;
	cin >> N >> x;
	vector<long long> a( N );
	long long all = 0;
	for( int i = 0; i < N; i++ ) {
		cin >> a[i];
		all += a[i];
	}

	int ans = 0;
	if( x <= all ) {
		sort( a.begin(), a.end() );
		for( int i = 0; i < N; i++ ) {
			if( x >= a[i] ) {
				x -= a[i];
				ans++;
			}
			else break;
		}
	}
	else ans = N - 1;

	cout << ans << endl;
}
