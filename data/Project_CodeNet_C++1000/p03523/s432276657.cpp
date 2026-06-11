#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	string T( "AKIHABARA" );
	int loc[4] = { 0, 4, 6, 8 };
	int N = T.size();
	vector<string> vt;
	for( int mask = 0; mask < 1 << 4; mask++ ) {
		string t = T;
		for( int i = 0; i < 4; i++ ) {
			if( mask >> i & 1 ) {
				t[ loc[i] ] = '0';
			}
		}
		for( int j = t.size() - 1; j >= 0; j-- ) {
			if( t[j] == '0' ) t.erase( t.begin() + j );
		}
		vt.push_back( t );
	}
	string ans = "NO";
	for( int i = 0; i < vt.size(); i++ ) {
		if( vt[i] == S ) {
			ans = "YES";
			break;
		}
	}

	cout << ans << endl;
}
