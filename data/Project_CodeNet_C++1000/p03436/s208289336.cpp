#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int r, c, sy, sx, gy, gx; cin >> r >> c;
	sy = 1;
	sx = 1;
	gy = r;
	gx = c;
	vector<vector<char>> a(r + 2, vector<char>(c + 2, 'e'));
	int cnt = 0;
	for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) {
		cin >> a[i][j];
		if (a[i][j] == '#') cnt++;
	}

	// BFS のためのデータ構造
	vector<vector<int>> dist(r + 2, vector<int>(c + 2, -1)); // 全頂点を「未訪問」に初期化
	queue<pair<int, int>> que;

	// 初期条件
	dist[sy][sx] = 0;
	que.push({ sy,sx });

	const int dy[4] = { 1, 0, -1, 0 };
	const int dx[4] = { 0, 1, 0, -1 };

	// BFS 開始 (キューが空になるまで探索を行う)
	while (!que.empty()) {

		pair<int, int> p = que.front(); // キューから先頭頂点を取り出す
		que.pop();

		// p から辿れるマスをすべて調べる
		for (int i = 0; i < 4; i++) {

			int y_next = p.first + dy[i];
			int x_next = p.second + dx[i];

			if (dist[y_next][x_next] != -1) continue;
			if (a[y_next][x_next] == 'e' || a[y_next][x_next] == '#') continue;

			// 新たなマス { y_next, x_next } について距離情報を更新してキューに追加する
			dist[y_next][x_next] = dist[p.first][p.second] + 1;
			que.push({ y_next, x_next });

		}

	}
	if (dist[gy][gx] != -1) cout << r * c - (dist[gy][gx] + 1) - cnt << endl;
	else cout << -1 << endl;
    return 0;
}