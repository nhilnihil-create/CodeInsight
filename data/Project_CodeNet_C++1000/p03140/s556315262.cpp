#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	int N;
	string a, b, c;
	cin >> N >> a >> b >> c;

	int ans = 0;
	for( int i = 0; i < N; ++i ) {
		set<char> x { a[i], b[i], c[i] };
		ans += x.size() - 1;
	}
	cout << ans << endl;

	return 0;
}
