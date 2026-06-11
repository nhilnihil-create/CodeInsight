#include "bits/stdc++.h"
using namespace std;

struct Solver {
	Solver() {
		ios::sync_with_stdio( false );
		cout << fixed << setprecision( 10 );
	}

	void solve() {
		int N;
		cin >> N;

		double avg = 0;
		vector<int> a( N );
		for( auto& v: a ) {
			cin >> v;
			avg += v;
		}
		avg /= N;

		double d = DBL_MAX;
		int ans = N;
		for( int i = 0; i < N; ++i ) {
			double x = abs( a[i] - avg );

			if( x < d ) {
				d = x;
				ans = i;
			}
		}

		cout << ans << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
