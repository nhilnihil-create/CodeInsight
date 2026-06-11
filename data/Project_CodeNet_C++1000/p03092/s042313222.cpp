#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, X, Y; cin >> n >> X >> Y;
  vector<int> a(n);
  for(int &x : a) cin >> x;

  vector<vector<long long>> f(n + 1, vector<long long>(n + 2, 1e18));

  f[0][0] = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j <= n; ++j) {
      if(j > 0) f[i][j] = min(f[i][j], f[i][j - 1]);

      if(a[i] > j) {
        f[i + 1][a[i]] = min(f[i + 1][a[i]], f[i][j]);
        f[i + 1][j] = min(f[i + 1][j], f[i][j] + X);
      }
      else {
        f[i + 1][j] = min(f[i + 1][j], f[i][j] + Y);
      }
    }
  }

  cout << *min_element(f[n].begin(), f[n].end()) << endl;

  return 0;
}
