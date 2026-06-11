#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int hoge(vector<int> &ans, int x, int i, int v) { return x + ans[i - x * v]; }

int main() {
  vector<int> vec = {1};
  for (int i = 1; pow(6, i) <= 100000; ++i)
    vec.push_back(pow(6, i));
  for (int i = 1; pow(9, i) <= 100000; ++i)
    vec.push_back(pow(9, i));

  sort(vec.begin(), vec.end());

  vector<int> ans(100001, INT_MAX);
  ans[0] = 0;
  for (auto &v : vec) {
    for (int i = 1; i < 100001; ++i) {
      int x0 = 0;
      int x1 = i / v * 1 / 3;
      int x2 = i / v * 2 / 3;
      int x3 = i / v;
      int v0 = hoge(ans, x0, i, v);
      int v1 = hoge(ans, x1, i, v);
      int v2 = hoge(ans, x2, i, v);
      int v3 = hoge(ans, x3, i, v);
      while (3 < x3 - x0) {
        if (v1 <= v2 && v2 <= v3) {
          if (x1 - x0 < x2 - x1) {
            x3 = x2;
            x2 = (x1 + x2) / 2;
            v3 = v2;
            v2 = hoge(ans, x2, i, v);
          } else {
            x3 = x2;
            x2 = x1;
            x1 = (x0 + x1) / 2;
            v3 = v2;
            v2 = v1;
            v1 = hoge(ans, x1, i, v);
          }
        } else {
          if (x3 - x2 < x2 - x1) {
            x0 = x1;
            x1 = (x1 + x2) / 2;
            v0 = v1;
            v1 = hoge(ans, x1, i, v);
          } else {
            x0 = x1;
            x1 = x2;
            x2 = (x2 + x3) / 2;
            v0 = v1;
            v1 = v2;
            v2 = hoge(ans, x2, i, v);
          }
        }
      }
      ans[i] = min({v0, v1, v2, v3});
    }
  }

  int n;
  cin >> n;
  cout << ans[n] << endl;
}