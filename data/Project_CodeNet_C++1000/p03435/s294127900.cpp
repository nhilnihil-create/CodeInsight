#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<vector<int>> c( 3, vector<int>( 3 ) );
	for( int i = 0; i < 3; i++ ) {
		for( int j = 0; j < 3; j++ ) {
			cin >> c[i][j];
		}
	}

	string ans = "No";
	int a[3];
	int b[3];
	for( int ii = 0; ii <= 100; ii++ ) {
		a[0] = ii;
		for( int jj = 0; jj <= 100; jj++ ) {
			a[1] = jj;
			for( int kk = 0; kk <= 100; kk++ ) {
				a[2] = kk;
				int flag = 0;
				for( int i = 0; i < 3; i++ ) {
					for( int j = 0; j < 3; j++ ) {
						if( i == 0 ) b[j] = c[i][j] - a[i];
						else if( c[i][j] != a[i] + b[j] ) {
							flag = 1;
							break;
						}
					}
					if( flag ) break;
				}
				if( flag == 0 ) {
					ans = "Yes";
					break;
				}
			}
			if( ans == "Yes" ) break;
		}
		if( ans == "Yes" ) break;
	}

	cout << ans << endl;
}
