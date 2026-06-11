#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
static const int INF (1<<30);

int main() {
  int N; cin >> N;
  vector<tuple<ll, ll, ll> > v(N);
  rep(i, N) {
    ll a, b, sum;
    cin >> a >> b;
    sum = a + b;
    v[i] = make_tuple(sum, a, b);
  }

  sort(all(v));
  reverse(all(v));

  ll ans = 0LL;
  rep(i, N) {
    if ((i%2) == 0) {
      ans += get<1>(v[i]);
    } else {
      ans -= get<2>(v[i]);
    }
  }

  cout << ans << endl;

  return 0;
}
