#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int N;
  cin >> N;
  vector<int> C(N), S(N), F(N);
  for (int i = 1; i < N; i++) {
    cin >> C[i] >> S[i] >> F[i];
  }
  
  // i駅スタートで求める
  for (int i = 1; i <= N-1; i++) {
    //初期値は i駅目のスタート
    int ans = 0;
    for (int k = i; k <= N-1; k++) {
      //k駅について
      //今の時刻がS[k]以下なら次の出発はS[k]
      //そうでないなら，ans + F[k] - (ans % F[k]) が次の出発時刻
      if (ans <= S[k]) {
        ans = S[k];
      } else {
        if (ans % F[k]) {
        ans += F[k] - (ans % F[k]);
        }
      }
      // 移動時間
      ans += C[k];
    }
    
    cout << ans << endl;
  }
  
  cout << 0 << endl;

}