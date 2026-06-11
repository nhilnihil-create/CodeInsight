#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		int A, B, K;
		cin >> A >> B >> K;

		for( int i = 0; i < K; ++i ) {
			if( (i&1) == 0 ) {
				if( A&1 ) { A -= 1; }
				B += A/2;
				A /= 2;
			}
			else {
				if( B&1 ) { B -= 1; }
				A += B/2;
				B /= 2;
			}
		}

		cout << A << ' ' << B << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
