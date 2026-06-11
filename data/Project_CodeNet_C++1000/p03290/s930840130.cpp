#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  int D,G;
  cin >> D >> G;
  int p[D],c[D];
  for (int n = 0; n < D; n++) {
   cin >> p[n] >> c[n];
  }
  int ans = 1e9;
  // D番目のbitまでを使う
  for(int mask = 0; mask < (1 << D);++mask){
    int s =0, num = 0,rest_max = 0;
    for(int i = 0; i < D; ++i){
      //i番目のbitが立っているか確認する
      //立っているとき問題を完全に解く
      if(mask >> i & 1){
        s += 100*(i+1)*p[i] + c[i];
        num += p[i];
      }
      //立っていないときの問題数を数える（中途半端に解く
      else
        rest_max = i;
    }
    if(s < G){
      int s1 = 100 * (rest_max + 1);
      int need = (G - s + s1 - 1)/s1;
      if(need >= p[rest_max]){
        continue;
      }
      num += need;
    }
    ans = min(num, ans);
  }
  cout << ans << endl;
  return 0;
}
