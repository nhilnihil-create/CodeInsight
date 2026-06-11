#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> k(m);
  vector<vector<int>> s(m);
  vector<int> p(m);

  for (int i = 0; i < m; ++i) {
    cin >> k[i];
    s[i].resize(k[i]);
    for (int j = 0; j < k[i]; ++j) {
      cin >> s[i][j];
      --s[i][j];
    }
  }
  for (int k = 0; k < m; ++k) {
    cin >> p[k];
  }

  int ans = 0;
  for (int bits = 0; bits < (1 << n); ++bits) {
    bool all_ok = true;
    for (int i = 0; i < m; ++i) {
      int cnt = 0;
      for (int j = 0; j < k[i]; ++j) {
        if ((bits >> s[i][j]) & 1) cnt++;
      }
      if (p[i] != (cnt % 2)) all_ok = false;
    }
    if (all_ok) ++ans;
  }
  cout << ans << endl;
}
