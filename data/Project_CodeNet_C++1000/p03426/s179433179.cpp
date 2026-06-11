#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H,W,D;
  cin >> H >> W >> D;

  vector<pair<int,int>> Cood(H * W + 1);
  rep(h, H) {
    rep(w, W) {
      int A; cin >> A;
      Cood[A] = make_pair(h, w);
    }
  }

  vector<int> Cost(H * W + 1);

  // D = 2
  // d = 1
  rep1(d, D) {
    Cost[d] = 0; // Cost[1] = 1にいくまでのコスト
    for(int i = d + D; i <= (H * W); i += D) {
      pair<int,int> pre = Cood[i - D]; // 1の座標
      pair<int,int> nex = Cood[i]; // 3の座標
      Cost[i] = Cost[i - D] + abs(nex.first - pre.first) + abs(nex.second - pre.second);
    }
  }

  int Q; cin >> Q;
  rep(q, Q) {
    int l,r; cin >> l >> r;
    cout << Cost[r] - Cost[l] << endl;
  }
}
