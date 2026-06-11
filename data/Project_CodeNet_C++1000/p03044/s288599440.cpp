#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, start_index, num)  (a).begin()+(start_index),(a).begin()+(num)

using Graph = vector<vector<pair<int, int>>>;

int main() {
	int N;
	cin >> N;

	Graph G(N + 1);
	FOR(i, 1, N - 1) {
		ll u, v, w;
		cin >> u >> v >> w;
		w %= 2;
		G[u].push_back(MP(v, w));
		G[v].push_back(MP(u, w));
	}

	// BFS のためのデータ構造
	vector<int> iseven(N + 1, -1); // 全頂点を「未訪問」に初期化
	queue<int> que;

	// 初期条件 (頂点 1 を初期ノードとする)
	iseven[1] = 0;
	que.push(1); // 1 を橙色頂点にする

				 // BFS 開始 (キューが空になるまで探索を行う)
	while (!que.empty()) {
		int v = que.front(); // キューから先頭頂点を取り出す
		que.pop();

		// v から辿れる頂点をすべて調べる
		for (pair<int, int> nv : G[v]) {
			if (iseven[nv.first] != -1) continue; // すでに発見済みの頂点は探索しない

			// 新たな白色頂点 nv について距離情報を更新してキューに追加する
			iseven[nv.F] = (iseven[v] + nv.S) % 2;
			que.push(nv.F);
		}
	}

	// 結果出力 (各頂点の頂点 1 からの距離を見る)
	FOR(i, 1, N) {
		pv(iseven[i])
	}
}