#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	int N;
	cin >> N;

	vector<int> a( N );
	for( auto& v: a ) { cin >> v; }

	int ans = 0;
	int x = a[0];
	for( int i = 1; i < N; ++i ) {
		if( a[i] == x ) {
			x = 0;
			ans += 1;
		}
		else {
			x = a[i];
		}
	}
	cout << ans << endl;

	return 0;
}
