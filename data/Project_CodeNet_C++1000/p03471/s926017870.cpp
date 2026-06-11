#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, Y;
	cin >> N >> Y;

	long long ansa = -1;
	long long ansb = -1;
	long long ansc = -1;
	for( long long a = 0; a <= 2000; a++ ) {
		for( long long b = 0; b <= 2000; b++ ) {
			long long cy = Y - (a * 10000 + b * 5000);
			long long c = N - (a + b);
			if( cy < 0 || c < 0 ) continue;
			if( cy == c * 1000 ) {
				ansa = a;
				ansb = b;
				ansc = c;
				break;
			}
		}
	}

	cout << ansa << " " << ansb << " " << ansc << endl;
}
