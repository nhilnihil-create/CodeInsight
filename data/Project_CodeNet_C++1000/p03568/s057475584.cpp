#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;
const int MAX_N = 10;
vector<int> a(MAX_N);

int dfs(int d, int seki) {
  if (d == n) {
    if (seki % 2 == 0)
      return 1;
    else
      return 0;
  }

  int cnt = 0;
  rep(i, 3) { cnt += dfs(d + 1, seki * (a[d] + (-1 + i))); }
  return cnt;
}

int main() {
  cin >> n;
  rep(i, n) cin >> a[i];
  cout << dfs(0, 1) << endl;
  return 0;
}
