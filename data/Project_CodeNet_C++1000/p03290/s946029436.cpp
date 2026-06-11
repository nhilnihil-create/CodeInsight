#include <bits/stdc++.h>
using namespace std;
int main(){
  int D, G;
  cin >> D >> G;
  vector<int> p(D), c(D);
  for (int i = 0; i < D; i++){
    cin >> p[i] >> c[i];
  }
  int sum = 0;
  for (int i = 0; i < D; i++){
    sum += p[i];
  }
  int ans = sum;
  for (int i = 0; i < (1 << D); i++){
    int s = 0;
    int cnt = 0;
    for (int j = 0; j < D; j++){
      if (i >> j & 1){
        s += p[j] * (j + 1) * 100 + c[j];
        cnt += p[j];
      }
    }
    if (s >= G){
      ans = min(ans, cnt);
    } else {
      int mx = 0;
      for (int j = 0; j < D; j++){
        if (!(i >> j & 1)){
          mx = j;
        }
      }
      int cnt2 = (G - s + (mx + 1) * 100 - 1) / ((mx + 1) * 100);
      if (cnt2 <= p[mx]){
        ans = min(ans, cnt + cnt2);
      }
    }
  }
  cout << ans << endl;
}