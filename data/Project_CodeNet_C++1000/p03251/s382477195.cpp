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
  int N, M, X, Y; cin >> N >> M >> X >> Y;
  vector<int> x(N), y(M);
  rep(i,N) cin >> x[i];
  rep(i,M) cin >> y[i];
  sort(x.begin(), x.end(), greater<int>());
  sort(y.begin(), y.end());
  if (max(x[0], X) < min(y[0], Y)) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}