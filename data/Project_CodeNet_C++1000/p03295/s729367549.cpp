#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  int N, M;
  cin >> N >> M;
  vector<P> ab(M);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    ab[i].first = b;
    ab[i].second = a;
  }

  sort(ab.begin(), ab.end());

  int old = -1;
  int ans = 0;
  for (int i = 0; i < ab.size(); ++i) {
    if (!(ab[i].second <= old && old < ab[i].first)) {
      old = ab[i].first - 1;
      ++ans;
    }
  }

  cout << ans << endl;
  
  return 0;
}