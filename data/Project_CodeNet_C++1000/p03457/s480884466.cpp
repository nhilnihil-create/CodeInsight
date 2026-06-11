#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
typedef pair<int, int> P;

int main(){
  int N;
  cin >> N;

  vector<int> gtime(N);
  vector<P> gxy(N);
  rep(i,N){
    cin >> gtime.at(i);
    cin >> gxy.at(i).first >> gxy.at(i).second;
  }

  int gtpry, ggpry;//ゴール時間のパリティとゴール座標のパリティ；
  int sx = 0, sy = 0;
  int stime = 0;
  int gx, gy;

  bool flag = true;
  int dist;

  rep(i, N){
    gx = gxy.at(i).first; gy = gxy.at(i).second;

    dist = abs(gx-sx)+abs(gy-sy);
    gtpry = (gtime.at(i) - stime)%2;
    ggpry = dist%2;

    if((ggpry != gtpry) || dist > (gtime.at(i) - stime)){
      flag = false;
      break;
    }

    stime = gtime.at(i);
    sx = gx; sy = gy;
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
