#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n;
  cin >> n;
  string s;
  map<char, ll> mp;
  rep(i, n) {
    cin >> s;
    mp[s[0]]++;
  }
  vector<ll> d = {mp['M'], mp['A'], mp['R'], mp['C'], mp['H']};
  ll ans = 0;
  for (int i = 0; i <= 2; i++) {
    for (int j = i + 1; j <= 3; j++) {
      for (int k = j + 1; k <= 4; k++) {
        ans += d[i] * d[j] * d[k];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
