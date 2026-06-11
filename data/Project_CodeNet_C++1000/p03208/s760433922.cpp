#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  sort(h.begin(), h.end());
  int min_d = 1e9 + 7;
  for (int i = 0; i + k - 1 < n; ++i) {
    int h_max = h[i + k - 1];
    int h_min = h[i];
    min_d = min(min_d, h_max - h_min);
  }
  cout << min_d << endl;
  return 0;
}