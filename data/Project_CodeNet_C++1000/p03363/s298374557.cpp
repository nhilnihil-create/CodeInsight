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
  vector<ll> cum_sum;
  map<ll, ll> mp;
  ll sum = 0;
  mp[0] += 1;
  cin >> n;
  REP(i, n) {
    int x;
    cin >> x;
    sum += x;
    mp[sum] += 1;
  }
  ll ans = 0;
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    ll cnt = itr->second;
    if (2 <= cnt) {
      ans += cnt * (cnt - 1) / 2;
    }
  }
  cout << ans << endl;
}