#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> m(n);
  rep(i, n) cin >> m.at(i);

  int single_total = 0;
  rep(i, n) single_total += m.at(i);
  int remaining = x - single_total;

  int min_g = 1100;
  rep(i, n) min_g = min(min_g, m.at(i));

  int cnt = n;
  while (remaining >= min_g) {
    remaining -= min_g;
    cnt++;
  }

  cout << cnt << endl;
  return 0;
}