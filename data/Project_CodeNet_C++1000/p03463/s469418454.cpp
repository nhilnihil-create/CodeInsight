#include "bits/stdc++.h"
using namespace std;
using long_t = int64_t;

struct Solver {
	Solver() {
		ios::sync_with_stdio( false );
		cout << fixed << setprecision( 10 );
	}

	void solve() {
		int N, A, B;
		cin >> N >> A >> B;
		cout << ((B-A) & 1 ? "Borys" : "Alice") << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
