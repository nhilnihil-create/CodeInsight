#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 1e9 + 7;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<ll> cnt(26, 0);
  rep(i, n) ++cnt[s[i] - 'a'];
  ll ans = 1;
  rep(i, 26) ans = ans * (cnt[i] + 1) % MOD;
  --ans;
  cout << ans << endl;
  return 0;
}