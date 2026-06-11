#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

using namespace std;

typedef long long int ll;

const int N = 1e3 + 10;
const int M = 1e4 + 10;

struct block {
  int w, s, v;
  block(int a, int b, int c) {
    w = a, s = b, v = c;
  }
  bool operator<(const block &o) const {
    return s - o.w < o.s - w;
  }
};

int n;
vector<block> a;
ll dp[M + M];

void solve() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int w, s, v; cin >> w >> s >> v;
    a.emplace_back(w, s, v);
  }
  sort(a.begin(), a.end());
  for(int i = 0; i < n; ++i) {
    block& cur = a[i];
    for(int weight = cur.s; weight >= 0; --weight) {
      dp[weight + cur.w] = max(dp[weight + cur.w], dp[weight] + cur.v);
    }
  }
  ll ans = 0;
  for(int i = 0; i < M + M; ++i) ans = max(ans, dp[i]);
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(9);
  cout << fixed;
  solve();
  return 0;
}
