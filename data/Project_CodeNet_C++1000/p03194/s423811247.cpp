#include <bits/stdc++.h>
using namespace std;

long long N, P;

typedef pair<long long, long long> PP;
vector<PP> vp;

int main() {
	cin >> N >> P;

	long long rt = (long long)sqrt( (double)P );
	long long n = P;
	for( long long i = 2; i <= rt; i++ ) {
		long long j;
		for( j = 0; n % i == 0; j++ ) {
			n /= i;
		}
		if( j ) {
			vp.push_back( make_pair( i, j ) );
		}
	}
	if( n > rt ) {
		vp.push_back( make_pair( n, 1 ) );
	}
	long long sz = vp.size();
	long long ans = 1;
	for( long long i = 0; i < sz; i++ ) {
		long long n = vp[i].second;
		while( n >= N ) {
			ans *= vp[i].first;
			n -= N;
		}
	}

	cout << ans << endl;

	return 0;
}
