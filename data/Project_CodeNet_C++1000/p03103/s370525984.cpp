#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
ll Mod = 1000000007;
int main() {
  ll N,M;
  cin >> N >> M;
  vector<P> D(N);
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> D[i].F >> D[i].S;
  }
  sort(D.begin(),D.end());
  for (int i = 0; i < N; i++) {
    if (M >= D[i].S) {
      ans += D[i].S * D[i].F;
      M -= D[i].S;
    } else {
      ans += D[i].F * M;
      M = 0;
    }
  }
  cout << ans << endl;
  return 0;
}