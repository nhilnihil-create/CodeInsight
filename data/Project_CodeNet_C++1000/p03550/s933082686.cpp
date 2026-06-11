#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N; cin >> N;  
  ll Z; cin >> Z;
  ll W; cin >> W;
  vector<ll> A(N); for (ll i = 0; i < N; i++) cin >> A[i];

  ll ans = abs(W - A[N - 1]);
  if (N > 1) ans = max(ans, abs(A[N - 1] - A[N - 2]));
  cout << ans << '\n';
  return 0;
}