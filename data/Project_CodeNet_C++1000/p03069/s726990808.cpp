#include "bits/stdc++.h"
using namespace std;

struct Solver {
	void solve() {
		int N;
		string S;
		cin >> N >> S;

		vector<int> b( N+1 ), w( N+1 );
		for( int i = 0; i < N; ++i ) {
			b[i+1] = b[i] + (S[i] == '#');
			w[i+1] = w[i] + (S[i] == '.');
		}

		int ans = INT_MAX;
		for( int i = 0; i <= N; ++i ) {
			int x = b[i];
			int y = w[N] - w[i];
			ans = min( ans, x+y );
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
