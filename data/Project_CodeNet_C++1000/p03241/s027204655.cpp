#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  set<int> factor;
  for (int i = 1; i * i <= m; ++i) {
    if (m % i == 0) {
      factor.insert(i);
      factor.insert(m / i);
    }
  }
  int ans = 1;
  for (auto itr = factor.begin(); itr != factor.end(); ++itr) {
    int g = *itr;
    if (m / g >= n) ans = g;
  }
  cout << ans << endl;
  return 0;
}