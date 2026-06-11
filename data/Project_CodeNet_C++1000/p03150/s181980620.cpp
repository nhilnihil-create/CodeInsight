#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	string ptn = "keyence";
	int n = ptn.size();
	string ans = "NO";
	if( S == ptn ) ans = "YES";
	if( S.substr( 0, n ) == ptn ) ans = "YES";
	if( S.substr( S.size() - n, n ) == ptn ) ans = "YES";
	for( int i = 1; ans == "NO" && i < ptn.size(); i++ ) {
		string s1 = ptn.substr( 0, i );
		string s2 = ptn.substr( i, n - i );
		if( S.substr( 0, i ) == s1 && S.substr( S.size() - (n - i), n - i ) == s2 ) ans = "YES";
	}

	cout << ans << endl;
}
