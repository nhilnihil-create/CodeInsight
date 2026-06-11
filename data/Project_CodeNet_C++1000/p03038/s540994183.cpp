#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  map<ll, ll> mp;
  vector<ll> k;
  rep(i, n) {
    ll a;
    cin >> a;
    if (mp.count(a) == 0) k.push_back(a);
    mp[a]++;
  }
  rep(i, m) {
    ll b, c;
    cin >> b >> c;
    if (mp.count(c) == 0) k.push_back(c);
    mp[c] += b;
  }
  sort(k.begin(), k.end());
  reverse(k.begin(), k.end());
  int i = 0;
  ll total = 0;
  while (n > 0) {
    int t = mp[k[i]];
    total += min(t, n) * k[i];
    n -= t;
    i++;
  }
  cout << total << endl;
}
