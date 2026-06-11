#include <bits/stdc++.h>
using namespace std;

int n, k, q;
int a[2000];

int sub(int t) {
  vector<vector<int>> vs;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    if (a[i] < t) {
      vs.push_back(v);
      v.clear();
    } else {
      v.push_back(a[i]);
    }
  }
  
  if (!v.empty()) {
    vs.push_back(v);
  }
  
  vector<int> r;
  for (auto&& v : vs) {
    if (v.size() < k) continue;
    sort(v.begin(), v.end());
    int len = v.size() - k + 1;
    for (int i = 0; i < len; ++i) {
      r.push_back(v[i]);
    }
  }
  
  sort(r.begin(), r.end());
  if (r.size() < q) return 2e9;
  return r[q - 1] - t;
}

int main() {
  cin >> n >> k >> q;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  int mn = 2e9;
  for (int i = 0; i < n; ++i) {
    int tmp = sub(a[i]);
    mn = min(mn, tmp);
  }
  cout << mn << endl;
}