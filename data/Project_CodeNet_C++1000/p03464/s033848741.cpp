#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int k;
  cin >> k;
  ll a[k];
  REP(i, k) cin >> a[i];
  ll ok = 1e18, ng = 0;
  while (1 < abs(ok - ng)) {
    ll mid = (ok + ng) / 2;
    ll n = mid;
    REP(i, k) n = a[i] * (n / a[i]);
    (2 <= n ? ok : ng) = mid;
  }
  ll mn = ok;
  ok = 0, ng = 1e18;
  while (1 < abs(ok - ng)) {
    ll mid = (ok + ng) / 2;
    ll n = mid;
    REP(i, k) n = a[i] * (n / a[i]);
    (n <= 2 ? ok : ng) = mid;
  }
  ll mx = ok;
  if (mx < mn) {
    puts("-1");
    return 0;
  }
  cout << mn << " " << mx << endl;
  return 0;
}