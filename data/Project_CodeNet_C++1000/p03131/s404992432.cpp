#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define FOR(i, b, n) for (ll i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

void solve(ll K, ll A, ll B) {
  if (B - A <= 2 || K < A + 1) {
    cout << K + 1 << endl;
    return;
  }
  K -= (A + 1);
  ll ans = B;
  ans += (K / 2) * (B - A) + (K % 2);
  cout << ans << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll K;
  cin >> K;
  ll A;
  cin >> A;
  ll B;
  cin >> B;

  solve(K, A, B);

  return 0;
}
