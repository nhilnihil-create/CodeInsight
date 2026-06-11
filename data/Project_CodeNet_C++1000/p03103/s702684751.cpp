#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main () {
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> ab(n);
  rep(i, n) cin >> ab[i].first >> ab[i].second;
  sort(ab.begin(), ab.end());

  pair<ll, ll> ans(0, 0);
  rep(i, n) {
    if (m - ans.second > ab[i].second) {
      ans.first += ab[i].first * ab[i].second;
      ans.second += ab[i].second;
    }
    else {
      ans.first += ab[i].first * (m - ans.second);
      ans.second = m;
      break;
    }
  }

  cout << ans.first << endl;

}
