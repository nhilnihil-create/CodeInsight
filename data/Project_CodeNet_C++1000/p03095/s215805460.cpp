#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
  int n;
  string s;
  cin >> n >> s;
  map<char, int> mp;
  rep(i, n) mp[s[i]]++;
  ll ans = 1;
  for (auto x : mp) ans = (ans * (x.second + 1)) % MOD;
  cout << ans - 1 << endl;
  return 0;
}
