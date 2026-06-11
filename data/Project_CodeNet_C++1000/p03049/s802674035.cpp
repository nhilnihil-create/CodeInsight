#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<string> s( N );
	for( int i = 0; i < N; i++ ) {
		cin >> s[i];
	}

	long long anum = 0;
	long long bnum = 0;
	long long abnum = 0;
	long long num = 0;
	for( int i = 0; i < N; i++ ) {
		if( s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A' ) abnum++;
		else if( s[i][0] == 'B' ) bnum++;
		else if( s[i][s[i].size() - 1] == 'A' ) anum++;
		int n = 0;
		while( 1 ) {
			n  = s[i].find( "AB", n );
			if( n == string::npos ) break;
			num++;
			n += 2;
		}
	}
	long long ans = num;
	if( abnum == 0 ) {
		ans += min( anum, bnum );
	}
	else if( abnum && anum && bnum ) {
		anum--;
		bnum--;
		ans += abnum + 1 + min( anum, bnum );
	}
	else if( abnum && anum || bnum ) {
		if( anum > bnum ) anum--;
		else bnum--;
		ans += abnum + min( anum, bnum );
	}
	else if( abnum > 1 ) {
		ans += abnum - 1;
	}

	cout << ans << endl;
}
