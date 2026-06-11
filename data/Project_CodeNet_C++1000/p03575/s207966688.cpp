#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

int main() {

    // 頂点数と辺数
    int N, M; cin >> N >> M;
    vector<int> a(M), b(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    for (int k = 0; k < M; k++) {
        // グラフ入力受取 (ここでは無向グラフを想定)
        Graph G(N);
        for (int i = 0; i < M; ++i) {
            if (i == k) continue;
            int tmp_a, tmp_b;
            tmp_a = a[i];
            tmp_b = b[i];
            tmp_a--;
            tmp_b--;
            G[tmp_a].push_back(tmp_b);
            G[tmp_b].push_back(tmp_a);
        }
        // BFS のためのデータ構造
        vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
        queue<int> que;

        // 初期条件 (頂点 0 を初期ノードとする)
        dist[0] = 0;
        que.push(0); // 0 を橙色頂点にする

        // BFS 開始 (キューが空になるまで探索を行う)
        while (!que.empty()) {
            int v = que.front(); // キューから先頭頂点を取り出す
            que.pop();

            // v から辿れる頂点をすべて調べる
            for (int new_v : G[v]) {
                if (dist[new_v] != -1) continue; // すでに発見済みの頂点は探索しない

                // 新たな白色頂点 new_v について距離情報を更新してキューに追加する
                dist[new_v] = dist[v] + 1;
                que.push(new_v);
            }
        }
        for (int i = 0; i < N; i++) {
            if (dist[i] == -1) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
	return 0;
}