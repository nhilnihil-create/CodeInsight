#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, ans = 0, four = 0, two = 0, tf = 0, sf = 0, ft = 0;
  cin >> n;
  map<int, int> mp;

  for (int i = 2; i <= n; ++i) {
    int t = i, j = 2;
    while (j * j <= i && t > 1)
      if (t % j == 0)
        mp[j]++, t /= j;
      else
        j++;

    if (t > 1) mp[t]++;
  }

  for (auto m : mp) {
    if (m.second >= 74) sf++;
    if (m.second >= 24) tf++;
    if (m.second >= 14) ft++;
    if (m.second >= 4) four++;
    if (m.second >= 2) two++;
  }

  ll m4 = sf + tf + ft + four;
  ans += sf;
  ans += tf * (two - 1);
  ans += ft * (four - 1);
  ans += four * (four - 1) * (two - 2) / 2;

  cout << ans << endl;
  return 0;
}