#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main()
{
  int N;
  cin >> N;
  vector<ll> vec(N);
  vector<ll> left(N+1, 0);
  vector<ll> right(N+1, 0);
  REP(i, N) {
    cin >> vec[i];
  }
  for (int i = 0; i < N; i++) {
    left[i+1] = gcd(left[i], vec[i]);
  }
  for (int i = N-1; 0 <= i; i--) {
    right[i] = gcd(right[i+1], vec[i]);
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, gcd(left[i], right[i+1]));
  }
  
  cout << ans << endl;
  return 0;
}