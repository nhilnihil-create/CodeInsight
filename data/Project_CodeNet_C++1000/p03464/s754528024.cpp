#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  bool ok = true;
  ll N;
  cin>>N;
  vector<ll> K(N+1);
  vector<ll> L(N+1), R(N+1);
  for(ll i=1; i<=N; i++)
    cin>>K[i];
  L[N] = R[N] = 2;
  for (ll i=N-1; i>=0; i--) {
    ll l = ((L[i+1] + K[i+1] - 1) / K[i+1]) * K[i+1];
    ll r = (R[i+1] / K[i+1]) * K[i+1];
    L[i] = l;
    R[i] = r + K[i+1]-1;
    if (L[i] > R[i])
      ok = false;
  }
  //for (ll i=0; i<=N; i++) {
  //  printf("i=%d: %d-%d\n", i, L[i], R[i]);
  //}

  if(ok)
    cout << L[0] << " " << R[0] << endl;
  else
    cout << -1 << endl;
  return 0;
}
