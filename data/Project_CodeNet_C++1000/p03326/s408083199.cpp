#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,M;
  cin >> N >> M;

  vector<ll> a[3];
  rep(i, N) {
    rep(j, 3) {
      ll tmp; cin >> tmp;
      a[j].push_back(tmp);
    }
  }

  ll ans = -1;

  for(int bit = 0; bit < (1<<3); bit++) {
    vector<ll> b(N);
    rep(i, N) {
      ll tmp = 0;
      rep(j, 3) {
        if((bit >> j) & 1) tmp += a[j][i];
        else tmp -= a[j][i];
      }
      b[i] = tmp;
    }
    sort(b.begin(), b.end(), greater<ll>());
    ll sum = 0;
    rep(i, M) sum += b[i];
    ans = max(ans, sum);
  }

  cout << ans << endl;
}
