#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, k;
  string s;
  cin >> n >> k >> s;

  vector<pair<char, int>> vec(1, P(s[0], 0));
  rep(i, n) {
    if (vec.back().first == s[i]) {
      vec.back().second++;
    } else {
      vec.emplace_back(s[i], 1);
    }
  }

  int m = vec.size();
  vector<ll> d(m + 1, 0);
  rep(i, m) d[i + 1] = d[i] + vec[i].second;

  ll ans = 0;
  rep(i, m) {
    int j = i + 2 * k;
    if (vec[i].first == '1') j++;
    j = min(j, m);
    ll tmp = d[j] - d[i];
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
