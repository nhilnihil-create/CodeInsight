#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> a(n, vector<bool>(m, false));
  rep(i, n) {
    int k;
    cin >> k;
    rep(j, k) {
      int aa;
      cin >> aa;
      aa--;
      a.at(i).at(aa) = true;
    }
  }

  int res = 0;
  rep(i, m) {
    bool like = true;
    rep(j, n) {
      if (!a.at(j).at(i)) {
        like = false;
        break;
      }
    }
    if (like) {
      res++;
    }
  }
  cout << res << endl;
  return 0;
}
