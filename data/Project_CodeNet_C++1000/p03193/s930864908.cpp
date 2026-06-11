#include "bits/stdc++.h"
using namespace std;

struct Solver {
	Solver() {
		ios::sync_with_stdio( false );
		cout << fixed << setprecision( 10 );
	}

	void solve() {
		int N, H, W;
		cin >> N >> H >> W;
		int ans = 0;
		for( int i = 0; i < N; ++i ) {
			int a, b;
			cin >> a >> b;
			ans += a >= H && b >= W;
		}
		cout << ans << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
