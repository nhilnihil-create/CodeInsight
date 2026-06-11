#include<bits/stdc++.h>
using namespace std;

struct Block {
  int w, s;
  long long v;
  Block(int w, int s, int v) : w(w), s(s), v(v) {}
  bool operator<(const Block& oth) const { return w + s < oth.w + oth.s; }
};

long long dp[1<<16] = {0};
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<Block> Bs;
  for (int i = 0; i < n; ++i) {
    int w, s, v; cin >> w >> s >> v;
    Bs.emplace_back(w, s, v);
  }
  sort(Bs.begin(), Bs.end());
  for (auto B : Bs) {
    int W = B.w, s = B.s;
    for (int w = s; w >= 0; --w) {
      dp[w + W] = max(dp[w] + B.v, dp[w + W]);
    }
  }
  cout << *max_element(dp, dp + (1<<16)) << '\n';
}
