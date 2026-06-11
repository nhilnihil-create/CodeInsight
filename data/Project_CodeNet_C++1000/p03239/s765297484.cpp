#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9 // INF = Infinity 無限　最小値を求めるときによく使う　
int main() {
  //入力
  int n,t;
  cin >> n >> t;
  vector<int> c(n),d(n);
  rep(i,n) cin >> c.at(i) >> d.at(i);

  //処理部分
  int ans = INF;//無限で初期化しておく(実用上は十分大きい数)
  rep(i,n){
    // 時間内につくものについてコストの最小値をとる
    if(d.at(i)<=t){
      ans = min(ans,c.at(i));
    }
  }
  // 時間内につくものがないなら最小値の更新はされてないはず
  if(ans==INF){
    cout <<  "TLE" << endl;
  }else{
    cout << ans << endl;
  }
}

