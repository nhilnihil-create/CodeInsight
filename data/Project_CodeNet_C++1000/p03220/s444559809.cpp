#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N, T, A;
  cin >> N >> T >> A;
  vector <int> H(N);
  rep(i,N) cin >> H[i];

  int ans = 0;
  double tmp = 100000.0;  //温度差の最小値を格納
  rep(i,N){
    double diff = abs(T - H[i] * 0.006 - A);  //A度との差
    if (diff == min(diff, tmp)) ans = i;  //温度差の最小値を更新したときansにiを代入
    tmp = min(diff, tmp);
  }
  cout << ans + 1 << endl;
}
