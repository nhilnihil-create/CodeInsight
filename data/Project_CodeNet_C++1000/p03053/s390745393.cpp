#include <bits/stdc++.h>

using namespace std;

//ABC007-Cの問題

struct mazepoint {
	int y;
	int x;
	int fukasa;
};

int main() {

	int h, w;
	cin >> h >> w;

	//int sy, sx;
	//cin >> sy >> sx;
	//sy--;
	//sx--;
	//int gy, gx;
	//cin >> gy >> gx;
	//gy--;
	//gx--;

	vector<int> mukix{ 1,0,-1,0 };
	vector<int> mukiy{ 0,1,0,-1 };

	vector<deque<mazepoint>> todo;					//行く所のスタック
	vector<vector<bool>> seen(h + 1, vector<bool>(w + 1));	//発見したらtrue

	//迷路読み込み
	vector<string> maze(h + 1);
	int counter = 0;
	for (int i = 0; i < h; i++) {
		cin >> maze[i];
		for (int j = 0; j < maze[i].size(); j++) {
			if (maze[i][j] == '#') {
				counter++;
				todo.resize(counter);
				todo[counter-1].push_back({ i,j,0 });
				seen[i][j] = true;
			}
		}
	}

	//幅優先探索処理



	//todo.push_back({ sy, sx });
	//mazepoint s = todo.front();							//今いる場所

	//seen[s.y][s.x] = true;
	//vector<vector<int>> fukasa(h + 1, vector<int>(w + 1, 0));

	int fukasa = -1;
	while (1) {				//vectorのtodoが全部空になるまで	

		fukasa++;
		for (int sh = 0; sh < counter; sh++) {

			while (todo[sh].empty()==false) { //その深さが終わるまで
				mazepoint s = todo[sh].front();						//処理番号を指定
				if (s.fukasa != fukasa) { break; }
				int tugiflg = false;					//次があったらtrueにするフラグ

				for (int i = 0; i < 4; i++) {

					int ny = s.y + mukiy[i];
					int nx = s.x + mukix[i];

					if (ny < 0 || nx < 0 || ny >= h || nx >= w) { continue; }
					if (maze[ny][nx] == '#') { continue; }
					if (seen[ny][nx]) { continue; }

					seen[ny][nx] = true;
					todo[sh].push_back({ ny,nx,fukasa+1 });
					tugiflg = true;
				}
				todo[sh].pop_front(); //次を全部探したので削除する
			}
		}

		bool brkflg = true;
		for (int sh = 0; sh < counter; sh++) {
			if (todo[sh].empty() == false) {
				brkflg = false;
			}
		}
		if (brkflg) { break; }
	}
	//	}

	cout << fukasa << endl;

	return 0;

}