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

	if( s[0][0] == '#' || s[H - 1][W - 1] == '#' ) {
		cout << -1 << endl;
		return 0;
	}
	vector<vector<int>> visit( H, vector<int>( W ) );
	typedef pair<int, int> P;
	vector<vector<P>> from( H, vector<P>( W ) );
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, 1, -1 };
	queue<P> que;
	que.push( P( 0, 0 ) );
	visit[0][0] = 1;
	int flag = 0;
	while( !que.empty() ) {
		int y, x;
		tie( y, x ) = que.front();
		que.pop();
		if( y == H - 1 && x == W - 1 ) {
			flag = 1;
			break;
		}
		for( int i = 0; i < 4; i++ ) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if( ny < 0 || ny >= H || nx < 0 || nx >= W ) continue;
			if( s[ny][nx] == '#' ) continue;
			if( visit[ny][nx] ) continue;
			que.push( P( ny, nx ) );
			visit[ny][nx] = 1;
			from[ny][nx] = P( y, x );
		}
	}
	if( flag == 0 ) {
		cout << -1 << endl;
		return 0;
	}
	set<P> st;
	int y = H - 1;
	int x = W - 1;
	while( 1 ) {
		st.insert( P( y, x ) );
		if( y == 0 && x == 0 ) break;
		int ny, nx;
		tie( ny, nx ) = from[y][x];
		y = ny;
		x = nx;
	}
	int ans = 0;
	for( int i = 0; i < H; i ++ ) {
		for( int j = 0; j < W; j++ ) {
			if( s[i][j] == '#' ) continue;
			if( st.count( P( i, j ) ) ) continue;
			ans++;
		}
	}

	cout << ans << endl;
}
