#include <bits/stdc++.h>

using namespace std;

//ABC079-Dの問題

void warshall_floyd(int n,vector<vector<int>> &d) {
	for (int k = 0; k < n; k++) {       // 経由する頂点
		for (int i = 0; i < n; i++) {    // 始点
			for (int j = 0; j < n; j++) {  // 終点
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {

	int h, w; //この問題専用
	cin >> h >> w;

	//10までの隣接行列を読み込む
	//この問題では有向きグラフG[始点][終点]
	vector<vector<int>> G(10, vector<int>(10));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> G[i][j];
		}
	}
	
	warshall_floyd(10, G);

	//こっからはこの問題専用。
	int summ = 0;
	int tmp;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> tmp;
			if (tmp != -1) {
				summ += G[tmp][1];
			}
		}
	}

	cout << summ << endl;

	return 0;

}