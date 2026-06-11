#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		string s;
		cin >> s;

		int n = (int)s.size();
		if( n == 26 ) {
			for( int i = n-1; i >= 0; --i ) {
				char ch = s[i];
				while( ++ch <= 'z' ) {
					if( s.find( ch ) >= (size_t)i ) {
						break;
					}
				}

				if( ch <= 'z' ) {
					cout << s.substr( 0, i ) << ch << endl;
					return;
				}
			}
		}
		else {
			for( char i = 'a'; i <= 'z'; ++i ) {
				if( s.find(i) >= (size_t)n ) {
					cout << s << i << endl;
					return;
				}
			}
		}

		cout << -1 << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();
	return 0;
}
