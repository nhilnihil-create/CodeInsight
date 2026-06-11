#include "bits/stdc++.h"
using namespace std;
using long_t = int64_t;

struct Solver {
	Solver() {
		ios::sync_with_stdio( false );
		cout << fixed << setprecision( 10 );
	}

	void solve() {
		int N;
		cin >> N;

		vector<int> A( N ), B( N );
		for( auto& v: A ) { cin >> v; }
		for( auto& v: B ) { cin >> v; }

		int ans = 0;
		long_t sum = 0;
		vector<int> C( N );
		for( int i = 0; i < N; ++i ) {
			if( A[i] < B[i] ) {
				sum += B[i] - A[i];
				ans += 1;
			}
			C[i] = A[i] - B[i];
		}
		sort( C.begin(), C.end(), greater<>() );

		for( int i = 0; i < N; ++i ) {
			if( sum <= 0 || C[i] <= 0 ) {
				break;
			}
			sum -= C[i];
			ans += 1;
		}

		cout << (sum > 0 ? -1 : ans) << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
