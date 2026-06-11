#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> field(H);
  for (int i=0; i<H; i++) cin >> field[i];
  // BFSのためのデータ構造(グリッドグラフ)
  // 全頂点を「未訪問」に初期化
  vector<vector<int>> dist(H, vector<int>(W, -1));
  queue<pair<int, int>> que;
  // 初期条件
  dist[0][0] = 1;
  que.push(make_pair(0, 0)); // スタート地点を発見済み頂点にする
  // BFS開始 (キューが空になるまで探索を行う)
  while (!que.empty()) {
    pair<int, int> p = que.front(); // キューから先頭頂点を取り出す
    que.pop();
    // pから辿れる頂点をすべて調べる
    for (int dir=0; dir<4; dir++) {
      int nh = p.first+dx[dir], nw = p.second+dy[dir];
      // 場外に出た場合と黒のマスに到達してしまった場合と訪問済みの点はスルー
      if (nh<0||nh>=H||nw<0||nw>=W) continue;
      if (field[nh][nw]=='#') continue;
      if (dist[nh][nw]!=-1) continue;
      dist[nh][nw] = dist[p.first][p.second]+1;
      que.push(make_pair(nh, nw));
    }
  }
  int white = 0;
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (field[i][j]=='.') white++;
    }
  }
  if (dist[H-1][W-1]==-1) cout << -1 << endl;
  else cout << white-dist[H-1][W-1] << endl;
  return 0;
}