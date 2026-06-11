#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  map<ll, ll> mp;
  priority_queue<int> que;
  rep(i, n) {
    int a;
    cin >> a;
    if (mp[a] == 0) {
      que.push(a);
    }
    mp[a] += 1;
  }
  rep(i, m) {
    ll b, c;
    cin >> b >> c;
    if (mp[c] == 0) {
      que.push(c);
    }
    mp[c] += b;
  }
  ll ans = 0;
  ll cnt = 0;
  while (cnt < n) {
    ll q = que.top();
    que.pop();
    ans += q * mp[q];
    cnt += mp[q];
    if (n < cnt) {
      ans -= q * (cnt - n);
    }
  }
  cout << ans << endl;
  return 0;
}
