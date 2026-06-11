#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		string S;
		cin >> S;
		int x = 15 - S.size();
		int y = count( S.begin(), S.end(), 'o' );
		cout << (x+y >= 8 ? "YES" : "NO") << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
