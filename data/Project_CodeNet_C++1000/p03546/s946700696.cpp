#include <bits/stdc++.h>

using namespace std;

//AOJ GRL_1_Cの問題
//こっちの方がより一般的かも

const long long inf = 1LL << 62;

void warshall_floyd(int n, vector<vector<long long>> &d) {
	for (int k = 0; k < n; k++) {       // 経由する頂点
		for (int i = 0; i < n; i++) {    // 始点
			if (d[i][k] == inf) { continue; }
			for (int j = 0; j < n; j++) {  // 終点
				if (d[k][j] == inf) { continue; }
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {

	int h, w;
	cin >> h >> w;

	int v, e; //頂点数、エッジ数
	//cin >> v >> e;
	v = 10;
	e = 100;

	//10までの隣接行列を読み込む
	//この問題では有向きグラフG[始点][終点]
	vector<vector<long long>> G(v, vector<long long>(v, inf));
	int in1;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			cin >> in1;
			G[i][j] = in1;
		}
	}

	warshall_floyd(v, G);

	//こっからはこの問題専用。
	long long res = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> in1;
			if (in1 != -1) {
				res += G[in1][1];
			}
		}
	}

	cout << res << endl;

	return 0;

}