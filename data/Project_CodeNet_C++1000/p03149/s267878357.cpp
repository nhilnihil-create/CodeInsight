#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	string n;
	for( int i = 0; i < 4; ++i ) {
		char c;
		cin >> c;
		n += c;
	}
	sort( n.begin(), n.end() );
	cout << (n == "1479" ? "YES" : "NO") << endl;

	return 0;
}
