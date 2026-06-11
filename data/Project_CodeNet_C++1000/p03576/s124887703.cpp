#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 4001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {

  int N, K;
  cin >> N >> K;
  vector<LLP> p(N);
  rep(i,N) cin >> p[i].first >> p[i].second;

  sort(p.begin(), p.end());

  ll ans = LINF;

  for (int i = 0; i < N; i++) {
    for (int j = i + K - 1; j < N; j++) {
      vector<ll> y;
      for (int k = i; k <= j; k++) y.push_back(p[k].second);
      sort(y.begin(), y.end());
      for (int k = 0; k + K - 1 < y.size(); k++) {
        ll area = (p[j].first - p[i].first) * (y[k + K - 1] - y[k]);
        ans = min(ans, area);
      }
    }
  }

  cout << ans << endl;

  return 0;
}