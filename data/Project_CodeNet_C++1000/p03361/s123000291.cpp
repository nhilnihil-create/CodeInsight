#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;

/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> field(H);
  REP(h,H) {
    string s;
    cin >> s;
    field[h] = s;
  }

  REP(h,H){
    REP(w,W){
      if(field[h][w] == '.') continue;
      bool ok = false;
      REP(dir,4){
        int nh = h+dx[dir];
        int nw = w+dy[dir];
        //範囲外スキップ
        if(nh < 0 || nw < 0) continue;
        if(nh >= H || nw >= W) continue;
        //
        if(field[nh][nw] == '#'){
          ok = true;
          break;
        }
      }
      if(!ok){
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}
