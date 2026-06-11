#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S, T;
	cin >> S >> T;

	auto f = []( string s, string t )
	{
		int N = s.size();
		for( int i = 0; i < N; i++ ) {
			if( s[i] != '?' && s[i] != t[i] ) return false;
		}
		return true;
	};
	int N = S.size();
	int NT = T.size();
	if( NT > N ) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	string ans;
	for( int i = N - NT; i >= 0; i-- ) {
		if( f( S.substr( i, NT ) , T ) ) {
			ans = S;
			ans.replace( i, NT, T );
			for( int i = 0; i < N; i++ ) if( ans[i] == '?' ) ans[i] = 'a';
			break;
		}
	}
	if( ans.size() == 0 ) cout << "UNRESTORABLE" << endl;
	else cout << ans << endl;
}
