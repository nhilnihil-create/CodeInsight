#include "bits/stdc++.h"
#define long int64_t
using namespace std;

struct Solver {
	void solve() {
		int N, M;
		cin >> N >> M;
		vector<vector<int>> cn( M );
		for( int i = 0; i < M; ++i ) {
			int k;
			cin >> k;
			for( int j = 0; j < k; ++j ) {
				int s;
				cin >> s;
				cn[i].push_back( s-1 );
			}
		}
		vector<int> p( M );
		for( int i = 0; i < M; ++i ) { cin >> p[i]; }

		int ans = 0;
		for( int swb = 0; swb < (1<<N); ++swb ) {
			bool ok = true;
			for( int i = 0; i < M; ++i ) {
				int onsw = 0;
				for( auto x: cn[i] ) {
					if( swb & (1 << x) ) { onsw += 1; }
				}
				if( onsw%2 != p[i] ) {
					ok = false;
					break;
				}
			}
			ans += ok;
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
