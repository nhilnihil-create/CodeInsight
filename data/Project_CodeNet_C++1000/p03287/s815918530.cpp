#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
#define in(v) v; cin >> v;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

int main() {
  int in(N); int in(M);

  vector<ll> sum(N+1, 0);
  map<ll, int> m;
  ++m[0];
  rep(i, N) {
    ll in(a);
    sum[i+1] = sum[i] + a;
    sum[i+1] %= M;
    ++m[sum[i+1]];
  }
  ll ans = 0;
  rep(i, N)
    ans += --m[sum[i+1]];
  cout << ans << endl;

  return 0;
}
