#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  vector<pair<int, int>> ans;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(a[i][j] % 2 == 0) {
        continue;
      }
      if(j != w - 1) {
        a[i][j]--;
        a[i][j + 1]++;
        ans.push_back({i, j});
      } else if(i != h - 1) {
        a[i][j]--;
        a[i + 1][j]++;
        ans.push_back({i, j});
      }
    }
  }
  cout << ans.size() << endl;
  for(const auto &p : ans) {
    if(p.second != w - 1) {
      cout << p.first + 1 << " " << p.second + 1 << " ";
      cout << p.first + 1 << " " << p.second + 2 << '\n';
    } else {
      cout << p.first + 1 << " " << p.second + 1 << " ";
      cout << p.first + 2 << " " << p.second + 1 << '\n';
    }
  }
  return 0;
}