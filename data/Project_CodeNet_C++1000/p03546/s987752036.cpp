#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

constexpr LL kInf = 1e18;
vector<vector<int>> d;

void warshal_floyd() {
  int V = d.size();
  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  int H, W; cin >> H >> W;
  d.resize(10, vector<int>(10));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> d[i][j];
    }
  }

  map<int, int> m;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      int a; cin >> a;
      if (a >= 0) m[a]++;
    }
  }

  warshal_floyd();

  int total = 0;
  for (auto p : m) {
    int key = p.first;
    int cnt = p.second;
    total += d[key][1] * cnt;
  }
  cout << total << endl;
}
