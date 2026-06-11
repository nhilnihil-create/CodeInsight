#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	Solver() {
		ios::sync_with_stdio( false );
	}

	void solve() {
		int N, A, B;
		cin >> N >> A >> B;

		int cnt[3] = {};
		for( int i = 0; i < N; ++i ) {
			int x;
			cin >> x;
			if( x <= A ) { cnt[0] += 1; }
			else if( x <= B ) { cnt[1] += 1; }
			else { cnt[2] += 1; }
		}

		cout << min( { cnt[0], cnt[1], cnt[2] } ) << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
