#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;
int a[25][25];

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  rep(i, m) cin >> b[i];

  int ans = 0;
  vector<int> sm(n, c);
  rep(i, n) {
    rep(j, m) {
      cin >> a[i][j];
      a[i][j] *= b[j];
      sm[i] += a[i][j];
    }
  }

  rep(i, n) {
    if (sm[i] > 0) ans++;
  }
  cout << ans;

  return 0;
}
