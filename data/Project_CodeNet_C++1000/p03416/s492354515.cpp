#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int ans = 0;
	for( int n = A; n <= B; n++ ) {
		char s[16];
		sprintf( s, "%d", n );
		string ss( s );
		int l = 0;
		int r = ss.size() - 1;
		int flag = 0;
		while( r > l ) {
			if( ss[l] != ss[r] ) {
				flag = 1;
				break;
			}
			l++;
			r--;
		}
		if( flag == 0 ) ans++;
	}

	cout << ans << endl;
}
