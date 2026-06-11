#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<ll> vec(n);
  vector<ll> d;
  rep(i, n) {
    cin >> vec[i];
    ll t = vec[i] - i - 1;
    d.push_back(t);
  }
  sort(d.begin(), d.end());
  ll ans = 0;
  ll med = d[n/2];
  rep(i, n) {
    ans += abs(d[i] - med);
  }
  cout << ans << endl;

  return 0;
}