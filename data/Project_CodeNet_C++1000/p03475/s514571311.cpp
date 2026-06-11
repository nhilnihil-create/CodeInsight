#include "bits/stdc++.h"
#define long int64_t
using namespace std;

struct Solver {
	void solve() {
		int N;
		cin >> N;
		vector<int> C( N ), S( N ), F( N );
		for( int i = 0; i < N-1; ++i ) {
			cin >> C[i] >> S[i] >> F[i];
		}

		for( int i = 0; i < N; ++i ) {
			int t = 0;
			for( int j = i; j < N-1; ++j ) {
				if( t < S[j] ) { t = S[j]; }
				else if( t % F[j] != 0 ) {
					t = t + F[j] - t % F[j];
				}
				t += C[j];
			}
			cout << t << endl;
		}
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
