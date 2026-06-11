#include <bits/stdc++.h>
using namespace std;

#define INF (INT32_MAX/2)
#define MAX 200000

int N, Q;
string s;
int t[MAX];
int d[MAX];

bool check( int i, int lr )
{
	int n = s[i] - 'A';
	for( int j = 0; j < Q; j++ ) {
		if( n != t[j] ) {
			continue;
		}
		if( d[j] ) {
			i++;
		}
		else {
			i--;
		}
		if( i < 0 ) {
			if( lr ) {
				return false;
			}
			else {
				return true;
			}
		}
		if( i >= N ) {
			if( lr ) {
				return true;
			}
			else {
				return false;
			}
		}
		n = s[i] - 'A';

	}
	return false;
}

int main() {
	cin >> N >> Q >> s;
	for( int i = 0; i < Q; i++ ) {
		char ct, cd;
		cin >> ct >> cd;
		t[i] = ct -'A';
		d[i] = 0;
		if( cd == 'R' ) {
			d[i] = 1;
		}
	}

	int l = -1;
	int r = N;
	while( r - l > 1 ) {
		int m = (r + l) / 2;
		if( check( m, 0 ) ) {
			l = m;
		}
		else {
			r = m;
		}
	}
	int cl = l;
	l = -1;
	r = N;
	while( r - l > 1 ) {
		int m = (r + l) / 2;
		if( check( m, 1 ) ) {
			r = m;
		}
		else {
			l = m;
		}
	}
	int cr = r;
	int ans = max( cr - cl - 1, 0 );

	cout << ans << endl;

	return 0;
}
