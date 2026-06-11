#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> div;
  for (int i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      div.push_back(i);
      if (m / i != i) div.push_back(m / i);
    }
  }
  sort(div.begin(), div.end());

  for (auto x : div) {
    if (n <= x) {
      cout << m / x << endl;
      return 0;
    }
  }
  return 0;
}
