#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a%b);
}

int main()
{
  int N;
  cin >> N;
  vector<ll> v(N);
  bool eq = true;
  REP(i, N) {
    cin >> v[i];
    if (i != 0) {
      if (v[i] != v[i-1]) {
        eq = false;
      }
    }
  }
  if (eq) {
    cout << v[0] << endl;
    return 0;
  }
  ll ans = v[0];

  for(int i = 1; i < N; i++) {
    ans = gcd(ans, v[i]);
  }
  cout << ans << endl;
  return 0;
}