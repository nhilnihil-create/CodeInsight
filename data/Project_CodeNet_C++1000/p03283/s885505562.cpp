#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> l(m), r(m);
  vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
  vector<int> p(q), p1(q);
  for(int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
    sum[l[i]][r[i]]++;
  }
  for(int i = 0; i < q; i++) {
    cin >> p[i] >> p1[i];
  }
  for(int i = 0; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      sum[i][j] += sum[i][j - 1];
    }
  }

  for(int i = 0; i < q; i++) {
    int ans = 0;
    for(int j = p[i]; j <= n; j++) {
      ans += sum[j][p1[i]];
    }
    cout << ans << '\n';
  }

  return 0;
}