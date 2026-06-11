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

		if( N%10 == 0 ) {
			cout << 10 << endl;
			return;
		}

		int ans = 0;
		while( N ) {
			ans += N%10;
			N /= 10;
		}

		cout << ans << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
