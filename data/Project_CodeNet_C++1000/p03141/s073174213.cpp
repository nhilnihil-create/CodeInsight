#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n;
  vector<ll> data;
  cin >> n;
  ll ans = 0;
  REP(i, n) {
    ll a, b;
    cin >> a >> b;
    data.push_back(a + b);
    ans -= b;
  }
  sort(ALL(data));
  reverse(ALL(data));
  REP(i, n) {
    if (i % 2 == 0) ans += data[i];
  }
  cout << ans << endl;
}