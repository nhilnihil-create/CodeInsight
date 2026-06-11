#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		int A, B, C;
		cin >> A >> B >> C;

		int ans = 0;
		if( B >= C ) {
			ans += B + C;
		}
		else {
			ans += B + B;
			C -= B;
			ans += min( A, C );
			C -= min( A, C );
			ans += C > 0;
		}

		cout << ans << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();

	return 0;
}
