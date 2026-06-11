#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll mod = 1e9 + 7;
constexpr int kMaxS = 1e4 + 5;

struct box {
  int w, s, v;
  bool operator< (const box& b) const {
    return s + w < b.s + b.w;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<box> boxes(n);
  for (int i = 0; i < n; ++i) {
    int w, s, v;
    cin >> w >> s >> v;

    boxes[i] = {w, s, v};
  }

  sort(boxes.begin(), boxes.end());

  for (const auto& b: boxes) {
    cerr << b.w << ' ' << b.s << ' ' << b.v << '\n';
  }

  vector<ll> dp(2 * kMaxS);
  for (int i = 0; i < n; ++i) {
    vector<ll> new_dp(dp);
    for (int w = boxes[i].s; w >= 0; --w) {
      new_dp[w + boxes[i].w] = max(new_dp[w + boxes[i].w], dp[w] + boxes[i].v);
    }
    swap(dp, new_dp);
  }

  cout << *max_element(dp.begin(), dp.end()) << '\n';

  return 0;
}
