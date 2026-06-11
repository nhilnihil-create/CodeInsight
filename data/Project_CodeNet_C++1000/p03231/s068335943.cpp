#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		long N, M;
		string S, T;
		cin >> N >> M >> S >> T;

		long g = gcd( N, M );
		long n = N / g;
		long m = M / g;
		long ans = M / g * N;
		for( long i = 0; i < g; ++i ) {
			if( S[i*n] != T[i*m] ) {
				ans = -1;
				break;
			}
		}

		cout << ans << endl;
	}

	template<class T> static T gcd( T a, T b ) { return b ? gcd( b, a%b ) : a; }
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
