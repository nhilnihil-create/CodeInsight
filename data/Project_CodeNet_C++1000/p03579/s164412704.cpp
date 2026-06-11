#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdint.h>
#include <queue>
#include <bitset>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

#define PI (3.14159265358979323846)
#define INF (2147483647)
#define INF_LL (9223372036854775807)
#define DIV_NUM (1000000007)



// BFSによる(隣接リスト)2部グラフ判定
#define MAX_E (100000)
#define MAX_V (100000)
int V, E; // V:頂点数、E:辺数
vector<int> G[MAX_V]; // 隣接リストでグラフを保持
int color[MAX_V];

bool bfs(int v) {

	// キューを用意して、初期探索点をセット
	queue <int> que;
	color[v] = 1;
	que.push(v);

	while (!que.empty()) { // BFSループ
		// ★★　この中で迂闊に break しないこと

		// キューの先頭のセルを取得
		int from = que.front(); que.pop();

		// 取得したセルに対する処理

		// そのセルからつながるセルに処理を移行
		for (int i = 0; i < G[from].size(); i++) {
			int to = G[from][i];

			if (color[to] == 0) {
				color[to] = -1 * color[from]; // 2色塗分け
				que.push(to);
			}
			else if(color[to] == color[from]) { // 2色塗分けに失敗
				return false;
			}
		}
	}
	return true;
}

int main() {

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		G[u - 1].push_back(v - 1);
		G[v - 1].push_back(u - 1); // 無向グラフ
	}

	fill(color, color + V, 0);

	// 2部グラフか否か
	bool BipartiteGraph = true;

	for (int i = 0; i < V; i++) {
		if (color[i] == 0) {
			if (!bfs(i)) BipartiteGraph = false;
		}
	}

	long long ans = 0;
	if (BipartiteGraph) {
		int one_count = 0;
		for (int i = 0; i < V; i++) {
			if (color[i] == 1) one_count++;
		}
		ans = (long long)(one_count) * (long long)(V - one_count) - (long long)(E);
	}
	else {
		ans = (long long)(V) * (long long)(V - 1) / 2 - (long long)(E);
	}

	cout << ans << endl;

	return 0;

}

