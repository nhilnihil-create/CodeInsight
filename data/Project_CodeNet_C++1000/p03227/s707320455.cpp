#include "bits/stdc++.h"
using namespace std;

struct Solver {
	void solve() {
		string S;
		cin >> S;

		if( S.size() == 3 ) {
			cout << S[2] << S[1] << S[0] << endl;
		}
		else {
			cout << S << endl;
		}
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();

	return 0;
}
