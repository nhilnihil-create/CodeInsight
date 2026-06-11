#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
  int N, K;
  cin >> N >> K;
  vector<P> v(N);
  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    v[i] = P(x, y);
  }
  sort(v.begin(), v.end(), [](P a, P b) {
    return a.first < b.first;
  });

  ll ans = -1;
  for (int l = 0; l < N-K+1; l++) {
    for (int r = l+K-1; r < N; r++) {
      vector<P> v2(r-l+1);
      copy(v.begin()+l, v.begin()+r+1, v2.begin());
      sort(v2.begin(), v2.end(), [](P a, P b) {
        return a.second < b.second;
      });
      ll dx = v[r].first - v[l].first;
      for (int i = 0; i < v2.size()-K+1; i++) {
        ll dy = v2[K-1+i].second - v2[i].second;
        ll area = dx * dy;
        ans = ans < 0 ? area : min(ans, area);
      }
    }
  }
  cout << ans << endl;
}