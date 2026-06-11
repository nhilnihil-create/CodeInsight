#include "bits/stdc++.h"
using namespace std;

struct Solver {
	Solver() {
		ios::sync_with_stdio( false );
		cout << fixed << setprecision( 10 );
	}

	void solve() {
		string n;
		cin >> n;
		cout << count( n.begin(), n.end(), '2' ) << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
