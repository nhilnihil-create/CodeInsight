#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define ALL(x) (x).begin(),(x).end()
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;

signed _main(){
  // 頂点数と辺数
  int H,W; cin >> H >> W;
  int dx[4]={1,0,-1,0};
  int dy[4]={0,1,0,-1};
  vv<char> field(H,v<char>(W));
  int cnt=0;
  rep(i,H)rep(j,W){
    cin >> field[i][j];
    if(field[i][j]=='#') cnt++;
  }

  // BFS のためのデータ構造
  vv<int> dist(H, v<int>(W,-1)); // 全頂点を「未訪問」に初期化
  queue<P> que;

  // 初期条件 (頂点 0 を初期ノードとする)
  dist[0][0] = 1;
  que.push(P(0,0)); // 0 を橙色頂点にする

  // BFS 開始 (キューが空になるまで探索を行う)
  while (!que.empty()) {
    P v = que.front(); // キューから先頭頂点を取り出す
    que.pop();

    // v から辿れる頂点をすべて調べる
    rep(i,4){
      int x=v.first+dx[i];
      int y=v.second+dy[i];
      if(x<0 || x>=H || y<0 || y>=W) continue;
      if(field[x][y]=='#') continue;
      if(dist[x][y]!=-1) continue;
      dist[x][y]=dist[v.first][v.second]+1;
      que.push(P(x,y));
    }
  }
  if(dist[H-1][W-1]==-1) cout << -1 << endl;
  else cout << H*W-cnt-dist[H-1][W-1] << endl;
}
