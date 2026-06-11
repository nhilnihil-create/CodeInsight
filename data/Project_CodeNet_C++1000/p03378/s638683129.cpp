#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(m);
  rep(i, m) cin >> a[i];

  vector<int> toll(n+1, 0);
  rep(i, m) toll[a[i]] = 1;

  int cost1 = 0;
  rep(i, x) cost1 += toll[i];

  int cost2 = 0;
  for (int i = x; i < n; ++i) cost2 += toll[i];

  int min_cost = min(cost1, cost2);
  cout << min_cost << endl;
  return 0;
}