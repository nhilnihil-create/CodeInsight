#include<bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v{0};
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    v.push_back(t);
  }
  v.push_back(0);
  int total = 0;
  auto dist = [&](int a, int b) -> int {
    return abs(v[a] - v[b]);
  };
  for (int i = 1; i <= n+1; i++) {
    total += dist(i, i-1);
  }
  for (int i = 1; i <= n; i++) {
    cout << total - dist(i, i-1) - dist(i, i+1) + dist(i-1, i+1) << endl;
  }
}