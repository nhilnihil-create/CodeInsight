#include <bits/stdc++.h>

using namespace std;

struct mazepoint {
	int y;
	int x;
};

int main() {

	int h, w;
	cin >> h >> w;
	int sy, sx;
	int gy, gx;

	sy = 1;
	sx = 1;
	gy = h;
	gx = w;
	
	vector<int> mukix{ 1,0,-1,0 };
	vector<int> mukiy{ 0,1,0,-1 };

	//迷路読み込み
	int kurokazu = 0;
	vector<string> maze(h + 2);
	for (int i = 1; i <= h; i++) {
		cin >> maze[i];

		for (int j = 0; j < w; j++) {
			if (maze[i][j] == '#') { kurokazu++; }
		}

		maze[i] = "#" + maze[i] + "#";
	}
	for (int i = 0; i <= w + 1; i++) {
		maze[0].push_back('#');
		maze[h+1].push_back('#');
	}


	//幅優先探索処理
	vector<vector<bool>> seen(h + 2, vector<bool>(w + 2));	//発見したらtrue
	deque<mazepoint> todo;					//行く所のスタック

	todo.push_back({ sy, sx });
	mazepoint s = todo.front();							//今いる場所

	seen[s.y][s.x] = true;
	vector<vector<int>> fukasa(h + 2, vector<int>(w + 2, 0));
	fukasa[sy][sx] = 1;

	while (todo.empty() != true) {				//スタックが空になるまで処理	
		s = todo.front();						//処理番号を指定
		int tugiflg = false;					//次があったらtrueにするフラグ
		for (int i = 0; i < 4; i++) {
			if (s.y + mukiy[i] == gy && s.x + mukix[i] == gx) {
				cout << w*h-kurokazu-fukasa[s.y][s.x]-1 << endl;
				return 0;
			}
			if (maze[s.y + mukiy[i]][s.x + mukix[i]] == '#') { continue; }
			if (seen[s.y + mukiy[i]][s.x + mukix[i]] != true) {
				seen[s.y + mukiy[i]][s.x + mukix[i]] = true;
				todo.push_back({ s.y + mukiy[i],s.x + mukix[i] });
				fukasa[s.y + mukiy[i]][s.x + mukix[i]] = fukasa[s.y][s.x] + 1;
				tugiflg = true;
				//				cout << s.y + mukiy[i] << " " << s.x + mukix[i] << endl;
			}
		}
		todo.pop_front(); //次を全部探したので削除する
	}
	//	}
	cout << -1 << endl;

	return 0;

}