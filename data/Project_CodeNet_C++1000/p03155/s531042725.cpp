#include "bits/stdc++.h"
#define long int64_t
using namespace std;

struct Solver {
	void solve() {
		int N, H, W;
		cin >> N >> H >> W;
		cout << (N-H+1) * (N-W+1) << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
