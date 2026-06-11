#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

//探索する方向を確認
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};


int main(){
  int H, W;
  cin >> H >> W;
  //端っこだけ，for文を分けると難しい？
  vector<string> s(H);
  REP(h,H) cin >> s[h];

  REP(h,H) REP(w,W){
    int cnt = 0;
    if(s[h][w] == '.'){
      REP(dir,8){
        int nh = h +dx[dir];
        int nw = w +dy[dir];
        //範囲外はスキップ
        if(nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if(s[nh][nw] == '#') ++cnt;
      }
      s[h][w] = cnt + '0';
    }
  }

  REP(h,H){
    cout << s[h] << endl;
  }

  return 0;
}
