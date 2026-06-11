#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, m, d, t;
  cin >> n;
  map<int, int> mp;
  rep(i, n) {
    cin >> d;
    mp[d]++;
  }
  cin >> m;
  rep(i, m) {
    cin >> t;
    if (mp[t] != 0) {
      mp[t]--;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
