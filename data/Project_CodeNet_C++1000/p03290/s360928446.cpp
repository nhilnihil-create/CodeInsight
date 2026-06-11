#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int D, G;
  cin >> D >> G;
  vector<int> P(D), C(D);
  rep(i, D) cin >> P[i] >> C[i];
  int ans = 1e9;
  for(int bit = 0; bit < (1 << D); ++bit){
    int s = 0, cnt = 0, remain_max = -1;
    for(int i = 0; i < D; ++i){
      if(bit >> i & 1){
        s += 100 * (i + 1) * P[i] + C[i];
        cnt += P[i];
      }else{
        remain_max = i;
      }
    }
    if (s < G){
      int s1 = 100 * (remain_max + 1);
      int need = (G - s + s1 - 1) / s1;
      if (need >= P[remain_max]) continue;
      cnt += need;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}
