#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int solve(vector<int> v1, vector<int> v2) {
  map<int, int> mp1;
  for (auto x : v1) mp1[x]++;
  int max_idx1, max_v1 = 0;
  for (auto x : mp1) {
    if (max_v1 < x.second) {
      max_idx1 = x.first;
      max_v1 = x.second;
    }
  }
  int ans1 = v1.size() - max_v1;

  map<int, int> mp2;
  for (auto x : v2) mp2[x]++;
  int max_v2 = 0;
  for (auto x : mp2)
    if (x.first != max_idx1) max_v2 = max(max_v2, x.second);
  int ans2 = v2.size() - max_v2;

  return ans1 + ans2;
}

int main() {
  int n, v;
  cin >> n;
  vector<int> v1, v2;
  rep(i, n) {
    cin >> v;
    if (i % 2 == 0)
      v1.push_back(v);
    else
      v2.push_back(v);
  }

  cout << min(solve(v1, v2), solve(v2, v1)) << endl;
  return 0;
}
