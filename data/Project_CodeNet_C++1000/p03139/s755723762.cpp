#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		int N, A, B;
		cin >> N >> A >> B;
		cout << min( A, B ) << ' ' << max( A+B-N, 0 ) << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
