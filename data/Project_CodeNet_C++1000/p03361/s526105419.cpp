#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> s( H );
	for( int i = 0; i < H; i++ ) {
		cin >> s[i];
	}

	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };
	string ans = "Yes";
	for( int y = 0; y < H; y++ ) {
		for( int x = 0; x < W; x++ ) {
			if( s[y][x] != '#' ) continue;
			int flag = 0;
			for( int i = 0; i < 4; i++ ) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if( ny < 0 || ny >= H || nx < 0 || nx >= W ) continue;
				if( s[ny][nx] == '#' ) {
					flag = 1;
					break;
				}
			}
			if( flag == 0 ) {
				ans = "No";
				break;
			}
		}
		if( ans == "No" ) break;
	}

	cout << ans << endl;
}
