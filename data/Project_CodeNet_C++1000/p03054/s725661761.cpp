#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int H, W, N, sr, sc;
	string S, T;
	cin >> H >> W >> N >> sr >> sc >> S >> T;

	string ans = "YES";
	int nl = sc;
	int nr = sc;
	int nu = sr;
	int nd = sr;
	for( int i = 0; i < N; i++ ) {
		if( S[i] == 'L' ) nl--;
		else if( S[i] == 'R' ) nr++;
		else if( S[i] == 'U' ) nu--;
		else if( S[i] == 'D' ) nd++;
		if( nl < 1 || nr > W || nu < 1 || nd > H ) {
			ans = "NO";
			break;
		}
		if( T[i] == 'L' ) {
			if( nr > 1 ) nr--;
		}
		else if( T[i] == 'R' ) {
			if( nl < W ) nl++;
		}
		else if( T[i] == 'U' ) {
			if( nd > 1 ) nd--;
		}
		else if( T[i] == 'D' ) {
			if( nu < H ) nu++;
		}
	}

	cout << ans << endl;
}
