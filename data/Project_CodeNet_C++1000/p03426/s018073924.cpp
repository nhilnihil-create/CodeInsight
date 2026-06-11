#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;

int main() {
  int H, W, D;
  cin >> H >> W >> D;
  vector<pair<int, int> > list(H * W + 1, pair<int, int>());
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int d;
      cin >> d;
      list[d] = make_pair(i, j);
    }
  }

  vector<ll> rw(H * W + 1, 0);
  for (int i = 1; i <= H * W - D; i++) {
    rw[i + D] = rw[i]
     + abs(list[i + D].first - list[i].first)
     + abs(list[i + D].second - list[i].second);
  }

  int Q;
  cin >> Q;
  while(Q--) {
    int l, r;
    cin >> l >> r;
    cout << rw[r] - rw[l] << endl;
  }

  return 0;
}
