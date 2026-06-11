#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S, T;
	cin >> S >> T;

	int N = S.size();
	map<char, char> mp;
	map<char, char> mp1;
	string ans = "Yes";
	for( int i = 0; i < N; i++ ) {
		if( mp.count( S[i] ) ) {
			if( mp[ S[i] ] != T[i] ) {
				ans = "No";
				break;
			}
		}
		else mp[ S[i] ] = T[i];
		if( mp1.count( T[i] ) ) {
			if( mp1[ T[i] ] != S[i] ) {
				ans = "No";
				break;
			}
		}
		else mp1[ T[i] ] = S[i];
	}

	cout << ans << endl;
}
