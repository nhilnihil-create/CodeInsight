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
  int N, M; cin >> N >> M;
  vector<pair<ll,ll>> p(N);
  rep(i,N) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());
  ll ans = 0;
  rep(i,N) {
    if (p[i].second >= M) {
      ans += p[i].first * M;
      break;
    }
    else {
      ans += p[i].first * p[i].second;
      M -= p[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}