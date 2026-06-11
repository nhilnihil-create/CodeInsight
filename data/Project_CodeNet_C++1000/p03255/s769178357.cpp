#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef unsigned long long ll;
typedef pair<int, int> pint;

int main() {
  int N;    ll X ; cin>>N>>X;
  vector<ll> x(N);
  REP(i,N) cin>>x[i];
  ll ans = 1LL<<62;

  reverse(x.begin(), x.end());
  // 累積和
  vector<ll> sum(N+1, 0LL);
  REP(i,N) sum[i+1] = sum[i] + x[i];
  for(int skip = 1; skip <= N; skip++) {
    ll work = 0LL;
    for(int i = 0; ; i++) {
      int a = i * skip;
      if(a >= N) break;
      int b = min((i+1) * skip, N);
      ll s = sum[b] - sum[a];
      if(i == 0) work += (ll)skip * X + 5LL * s;
      else {
	work += (ll)(3 + 2 * i) * s;
      }
    }
    ans = min(ans, work);
#ifdef DEBUG
    cout << skip << " " << work << " " << ans << endl;
#endif
  }
  cout << ans + (ll)N * X << endl;
  return 0;
}
