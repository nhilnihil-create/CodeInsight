#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, T; cin >> N >> T;
  vector<int> c(N), t(N);
  rep(i,N) cin >> c[i] >> t[i];
  int cost = 1010;
  rep(i,N) {
    if (t[i] <= T) cost = min(cost, c[i]);
  }
  if (cost == 1010) cout << "TLE" << endl;
  else cout << cost << endl;
  return 0;
}