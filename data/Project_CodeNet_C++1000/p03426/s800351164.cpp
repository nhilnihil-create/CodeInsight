#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int H,W,D;
  cin >> H >> W >> D;
  int A[H][W];
  vector<P> point((H*W)+1);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
      point[A[i][j]].first = i;
      point[A[i][j]].second = j;
    }
  }
  vector<int> dist[D];
  // distは累積和で表現
  for (int i = 0; i < D; i++) {
    for (int j = 0; (D * j) + i <= H * W; j++) {
      if (j == 0) {
        dist[i].push_back(0);
      } else {
        int num = (D * j) + i;
        int res = 0;
        res += abs(point[num].first - point[num-D].first);
        res += abs(point[num].second - point[num-D].second);
        dist[i].push_back(dist[i][j-1] + res);
      }
    }
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int l,r;
    cin >> l >> r;
    int s = l % D;
    l = (l - s) / D;
    r = (r - s) / D;
    int ans = dist[s][r] - dist[s][l];
    cout << ans << endl;
  }
  return 0;
}