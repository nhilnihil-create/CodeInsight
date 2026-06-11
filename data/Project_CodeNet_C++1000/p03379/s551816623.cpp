#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> X( N );
	for( int i = 0; i < N; i++ ) {
		cin >> X[i];
	}

	vector<long long> x = X;
	sort( x.begin(), x.end() );
	for( int i = 0; i < N; i++ ) {
		long long n = X[i];
		int idx = lower_bound( x.begin(), x.end(), n ) - x.begin();
		int l = 0;
		int r = N - 1;
		if( idx < N / 2 ) l++;
		else r--;
		long long ans = x[(l  + r) / 2];
		cout << ans << endl;
	}
}
