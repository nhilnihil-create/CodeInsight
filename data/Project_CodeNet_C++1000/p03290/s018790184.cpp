#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;
using namespace std;

int main() {
  int D, G, p[11], c[11];
  cin >> D >> G;
  rep(i,0,D) cin >> p[i] >> c[i];
  int ans = 1e9;
  for(int bit = 0; bit < (1 << D); ++bit){
    int s = 0, num = 0, rest_max = -1; 
    //sは得点の合計、numは解いた数の合計、rest_maxは解かなかった問題の中で最高点数の番号
    rep(i,0,D) {
      if(bit&1<<i) {
        s += 100 * (i+1) * p[i] + c[i];
        num += p[i];
      }
      else rest_max = i;
    }
    if(s < G) {
      int s1 = 100 * (rest_max + 1);
      int need = (G - s + (s1 - 1)) / s1; //rest_max番号の時にGを超えるために必要な試行回数を求める
      if(need >= p[rest_max]) continue; //中途半端に解く配点のためボーナス点数は考慮しない
      num += need;
    }
    ans = min(ans, num);
  }
  cout << ans << endl;
}
