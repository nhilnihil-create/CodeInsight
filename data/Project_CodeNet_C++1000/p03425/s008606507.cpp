#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> c( 5 );
	for( int i = 0; i < N; i++ ) {
		string s;
		cin >> s;
		if( s[0] == 'M' ) c[0]++;
		else if( s[0] == 'A' ) c[1]++;
		else if( s[0] == 'R' ) c[2]++;
		else if( s[0] == 'C' ) c[3]++;
		else if( s[0] == 'H' ) c[4]++;
	}

	long long ans = 0;
	int per[5] = { 0, 0, 1, 1, 1 };
	do {
		long long m = 1;
		for( int i = 0; i < 5; i++ ) {
			if( per[i] ) m *= c[i];
		}

		ans += m;
	} while( next_permutation( per, per + 5 ) );

	cout << ans << endl;
}
