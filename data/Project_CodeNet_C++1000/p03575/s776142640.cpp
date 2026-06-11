#include <bits/stdc++.h>

using namespace std;

int main() {

	int n,m;
	cin >> n >> m;

	int res = 0;

	vector<vector<int>> aa(m + 1,vector<int> (2));
	for(int i=1;i<=m;i++)	{
		cin >> aa[i][0] >> aa[i][1];
	}

	for (int k = 1; k <= m; k++) {

		vector < vector<int>> G(n + 1);

		//グラフ隣接リスト読み込み
		for (int i = 1; i <= m; i++) {
			if (i != k) {
				G[aa[i][0]].push_back(aa[i][1]);
				G[aa[i][1]].push_back(aa[i][0]);
			}
		}

		//幅優先探索処理
		vector<bool> seen(n + 1, false);	//発見したらtrue
		deque<int> todo;					//行く所のスタック

		int s = 1;							//今いる場所

		int j = 1; //この問題では１から到達できるところを調べる
		int counter = 1;

		if (seen[j] == false) {			//訪れてなかったら処理すすめる
			seen[j] = true;
			todo.push_back(j);

			while (todo.empty() != true) {				//スタックが空になるまで処理	
				s = todo.front();						//処理番号を指定
				int tugiflg = false;					//次があったらtrueにするフラグ
				for (int i = 0; i < G[s].size(); i++) {
					if (seen[G[s][i]] != true) {
						seen[G[s][i]] = true;
						todo.push_back(G[s][i]);
						counter++;
						tugiflg = true;
					}
				}
				todo.pop_front(); //次を全部探したので削除する
			}
		}

		if (counter != n) { res++; }

	}

	cout <<res << endl;

	return 0;
}