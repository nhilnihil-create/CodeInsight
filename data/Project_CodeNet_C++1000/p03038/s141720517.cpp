#include "bits/stdc++.h"
#define long int64_t
using namespace std;

struct Solver {
	void solve() {
		int N, M;
		cin >> N >> M;

		vector<int> A( N );
		for( int i = 0; i < N; ++i ) { cin >> A[i]; }
		sort( A.begin(), A.end() );

		vector<pair<int, int>> cb( M );
		for( int i = 0; i < M; ++i ) {
			int b, c;
			cin >> b >> c;
			cb[i] = { c, b };
		}
		sort( cb.begin(), cb.end(), greater<>() );

		priority_queue<int> q;
		for( int i = 0; i < M; ++i ) {
			int b = cb[i].second;
			while( q.size() < N && b-- ) { q.push( cb[i].first ); }
		}

		long ans = 0;
		for( int i = 0; i < N; ++i ) {
			int x = 0;
			if( !q.empty() ) {
				x = q.top();
				q.pop();
			}
			ans += max( x, A[i] );
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
