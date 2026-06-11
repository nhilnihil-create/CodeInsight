#include <iostream>
typedef long long ll;
using namespace std;

int main() {
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  ll ans = 1000000000000;
  // ABピザの数ごとで最小金額を計算する
  for (ll i=0; i <= 3000000; i+= 2ll) {
    ll cost = i * C;
    cost += A * max(0ll, X - i / 2ll);  // 0以下にならないようにAも買う
    cost += B * max(0ll, Y - i / 2ll);  // 0以下にならないようにBも買う
    ans = min(ans, cost);  // 前のiterationより小さかったら採用
  }
  
  cout << ans << endl;
}