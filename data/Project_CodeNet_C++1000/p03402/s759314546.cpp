#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A,B; cin >> A >> B;
  char G[50][100];

  // 上半分を黒で埋める
  rep(h, 50) {
    rep(w, 100) {
      G[h][w] = h < 25 ? '#' : '.';
    }
  }

  A--; B--;

  rep(h, 25) {
    if(A == 0) break;
    if(h % 2 != 0) continue;
    rep(w, 100) {
      if(w % 2 == 0) {
        G[h][w] = '.';
        A--;
        if(A == 0) break;
      }
    }
  }

  rep(h, 25) {
    if(B == 0) break;
    if(h % 2 != 0) continue;
    rep(w, 100) {
      if(w % 2 == 0) {
        G[h + 26][w] = '#';
        B--;
        if(B == 0) break;
      }
    }
  }

  cout << "50 100" << endl;

  rep(h, 50) {
    rep(w, 100) {
      cout << G[h][w];
    }
    cout << endl;
  }

  return 0;
}
