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

int main() {
  int H, W; cin >> H >> W;
  vector<vector<int>> a(H, vector<int>(W));
  vector<int> row(H, 0);
  for (int r = 0; r < H; ++r) {
    for (int c = 0; c < W; ++c) {
      cin >> a[r][c];
      row[r] += a[r][c];
    }
  }

  vector<string> ss;
  for (int r = 0; r < H; ++r) {
    int r2 = r + 1;
    for (int c = 0; c < W; ++c) {
      int c2 = c + 1;
      if (row[r] == 0) break;
      if (a[r][c] % 2 == 0) continue;
      if (r < H - 1 && row[r] % 2 != 0) {
        ss.push_back(to_string(r2) + " " + to_string(c2) + " " + to_string(r2 + 1) + " " + to_string(c2));
        --row[r];
        --a[r][c];
        ++row[r+1];
        ++a[r+1][c];
      } else if (c < W - 1) {
        ss.push_back(to_string(r2) + " " + to_string(c2) + " " + to_string(r2) + " " + to_string(c2 + 1));
        --a[r][c];
        ++a[r][c + 1];
      }
    }
  }

  cout << ss.size() << endl;
  for (string s : ss) cout << s << endl;
}
