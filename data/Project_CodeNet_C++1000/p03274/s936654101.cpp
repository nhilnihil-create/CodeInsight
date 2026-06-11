#include "bits/stdc++.h"
using namespace std;

struct Solver {
	Solver() {
		ios::sync_with_stdio( false );
		cout << fixed << setprecision( 10 );
	}

	void solve() {
		int N, K;
		cin >> N >> K;

		vector<int> x( N );
		for( auto& v: x ) { cin >> v; }

		int ans = INT_MAX;
		for( int i = 0; i < N-K+1; ++i ) {
			int a = x[i+K-1] - x[i];
			ans = min( { ans, abs( x[i] )+a, abs( x[i+K-1] )+a } );
		}

		cout << ans << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
