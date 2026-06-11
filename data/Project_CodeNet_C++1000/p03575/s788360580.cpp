#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)

const int limit = 50;
int n, m;
int a[limit], b[limit];
bool graph[limit][limit];
bool visited[limit];

void dfs(int v) {
    visited[v] = true;
    for (int v2 = 0; v2 < n; ++v2) { //頂点v2は、頂点vに隣接しているかつ未訪問ならdfsするループ
        if (graph[v][v2] == false) continue; //隣接してなかったらdfsしない
        if (visited[v2] == true) continue; //未訪問だったらdfsしない
        dfs(v2);
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--; //0スタートにするため
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true; //グラフを作る a-b辺はb-a辺でもある
    }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = false; //一つ辺を決めてfalseにする
        for (int j = 0; j < n; ++j) visited[j] = false; //visitedを初期化
        dfs(0); //0スタートで、グラフが連結か判定
        bool bridge = false; //非連結になる辺であればtrue
        for (int j = 0; j < n; ++j)
            if (visited[j] == false) bridge = true; //グラフの全部の頂点が辿れなければ非連結
        if (bridge) ans += 1; //非連結をカウント
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true; //最初にfalseにした辺をtrueに戻す
    }
    cout << ans << endl;
    return 0;
}