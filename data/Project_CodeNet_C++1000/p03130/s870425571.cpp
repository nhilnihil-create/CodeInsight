#include "bits/stdc++.h"
using namespace std;

struct Solver {
	Solver() {
		ios::sync_with_stdio( false );
		cout << fixed << setprecision( 10 );
	}

	void solve() {
		int x[4] = {};
		for( int i = 0; i < 3; ++i ) {
			int a, b;
			cin >> a >> b;
			x[a-1] += 1;
			x[b-1] += 1;
		}

		int y = 0;
		y += x[0] == 2;
		y += x[1] == 2;
		y += x[2] == 2;
		y += x[3] == 2;

		cout << (y == 2 ? "YES" : "NO") << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
