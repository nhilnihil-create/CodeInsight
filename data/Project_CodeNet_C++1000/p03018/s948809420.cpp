#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 200010;
int _w;

int n;
char s[N];
ll ans;

int main() {
	_w = scanf( "%s", s+1 );
	n = (int)strlen(s+1);
	int bc = 0;
	for( int i = n-1; i >= 1; ) {
		if( s[i] == 'B' && s[i+1] == 'C' ) {
			++bc;
			int j = i-1;
			while( j >= 1 && s[j] == 'A' ) {
				ans += bc;
				--j;
			}
			i = j-1;
		} else {
			bc = 0;
			--i;
		}
	}
	cout << ans << endl;
	return 0;
}
