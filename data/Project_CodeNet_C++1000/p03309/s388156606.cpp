#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n) a[i] -= i+1;
  sort(all(a));

  ll b = a[n/2];

  ll ans = 0;
  rep(i, n) ans += abs(a[i] - b);

  cout << ans << endl;

  return 0;
}
