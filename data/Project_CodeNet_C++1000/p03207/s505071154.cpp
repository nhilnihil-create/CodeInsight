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
  int N; cin >> N;
  vector<int> p(N);
  rep(i,N) cin >> p[i];
  sort(p.rbegin(), p.rend());
  p[0] /= 2;
  int ans = 0;
  rep(i,N) ans += p[i];
  cout << ans << endl;
  return 0;
}