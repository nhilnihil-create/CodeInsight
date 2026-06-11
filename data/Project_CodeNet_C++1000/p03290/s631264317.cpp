
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {

  int d,g;
  cin >> d >> g;
  vector<int>p(d);
  vector<int>c(d);
  rep(i,d){
    cin >> p[i]>> c[i];
  }
  ll ans = 1001;
  for(int bit = 0; bit < (1<<d); ++bit){
    ll sum = 0;
    ll cnt = 0;
    //全部解答
    rep(i,d){
      if(bit & (1<<i)) {
        sum += c[i] + p[i] * 100 * (i+1);
        cnt += p[i];
      }
    }
    if(sum >= g) ans = min(ans,cnt);
    else{
      //得点の大きい方からなるべく解答
      for(int i = d-1; i >= 0; i--){
        if (bit & (1<<i)) continue; // 全部解答はスキップ
        rep(j,p[i]){
          if (sum >= g) break;
          sum += 100 * (i+1);
          ++cnt;
        }
      }
      ans = min(ans,cnt);
    }
  }

  cout << ans << endl;
  return 0;

}