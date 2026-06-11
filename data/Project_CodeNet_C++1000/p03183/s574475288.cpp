#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
const int MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 1010, W = 2e4+10;

int n;
struct blk {
  int w, s, v;
  bool operator<(const blk& o) {
    return w+s > o.w + o.s;
  }
};

blk bs[N];
// dp[j] = max value for available wgt w
ll dp[2][W];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> bs[i].w >> bs[i].s >> bs[i].v;
  }
  sort(bs, bs + n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < W; j++) {
      dp[1][j] = dp[0][j];
    }
    for (int j = 0; j <= bs[i].s && j+bs[i].w < W; j++) {
      dp[1][j] = max(dp[0][j], dp[0][j+bs[i].w] + bs[i].v);
    }
    swap(dp[0], dp[1]);
  }
  cout << *max_element(dp[0], dp[0] + W) << nl;
  return 0;
}
