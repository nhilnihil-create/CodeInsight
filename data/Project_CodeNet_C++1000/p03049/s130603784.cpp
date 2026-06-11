#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	int N;
	cin >> N;

	vector<string> s( N );
	for( int i = 0; i < N; ++i ) {
		cin >> s[i];
	}

	int ab = 0;
	int a = 0;
	int b = 0;
	int ba = 0;
	for( int i = 0; i < N; ++i ) {
		for( int j = 1; j < s[i].size(); ++j ) {
			if( s[i][j-1] == 'A' && s[i][j] == 'B' ) { ab += 1; }
		}

		if( s[i].front() == 'B' && s[i].back() == 'A' ) {
			ba += 1;
		}
		else if( s[i].front() == 'B' ) {
			b += 1;
		}
		else if( s[i].back() == 'A' ) {
			a += 1;
		}
	}

	if( ba == 0 ) {
		cout << ab + min( a, b ) << endl;
	}
	else if( a == 0 && b == 0 ) {
		cout << ab + ba - 1 << endl;
	}
	else {
		cout << ab + ba + min( a, b ) << endl;
	}

	return 0;
}
