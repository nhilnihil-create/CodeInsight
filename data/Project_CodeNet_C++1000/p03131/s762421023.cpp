#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int k, a, b;
  cin >> k >> a >> b;
  ll bis = 1; // ビスケット
  ll yen = 0;
  if (a >= b) {
    bis += (ll) k;
  } else {
    rep(i, k) {
      int r = k - i - 1; // 残り
      if (yen > 0) {
        bis += b;
        yen--;
      } else if (bis >= a) {
        // ビスケットを叩いて増やすより、一旦円に交換してからの方が多いなら交換する
        if (r > 0 && (bis + r + 1) < (bis - a + b + (r - 1))) {
          bis -= a;
          yen++;
        } else {
          bis++;
        }
      } else {
        bis++;
      }
    }
  }
  cout << bis << endl;
  return 0;
}
