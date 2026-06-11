#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	string s;
	cin >> s;

	string t;
	for( int i = 0; i < s.size(); ++i ) {
		if( (s[i] == 'K' || s[i] == 'B' || s[i] == 'R') && (t == "" || s[i-1] != 'A') ) {
			t += 'A';
		}

		t += s[i];
	}

	if( t.back() == 'R' ) {
		t += 'A';
	}

	cout << (t == "AKIHABARA" ? "YES" : "NO") << endl;

	return 0;
}
