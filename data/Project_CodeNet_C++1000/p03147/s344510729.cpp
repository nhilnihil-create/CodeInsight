#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int max_elem(vector<int> X){
  vector<int> Y = X;
  sort(Y.begin(), Y.end());
  return Y[Y.size() - 1];
}

int main(){
  int N;
  cin >> N;
  vector<int> h(N);
  rep(i, N) cin >> h[i];

  // 連続する1を要素とするベクトルを足した回数
  int ans = 0;

  // 全てが0になるまで繰り返す
  while (true){
    // 全てが0ということは最大値が0ということ
    if (max_elem(h)==0) break;

    // みている花のインデックス
    int cnt = 0;
    // 1が連続する区間の最初であるかどうかのフラグ
    bool flag = true;

    // 全ての花を見る
    while (cnt < N){
      // もし見ている花の高さが0であればflagをtrueにする
      if (h[cnt]==0) flag=true;
      // 高さが0でないとき
      else{
        // 連続する区間の最初であればansをインクリメント
        if (flag) ans++;
        // 区間の最初はすぎたのでflagはfalseにする
        flag = false;
        h[cnt]--;
      }
      cnt ++;
    }
  }
  cout << ans << endl;
}