#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;

ll n, ans = 0;
void dfs(ll num) {
  if (num > n) return;
  
  vector<ll> ok(10, 0);
  string s = to_string(num);
  rep(i,s.size()) ok[s[i] - '0']++;
  if (ok[3] && ok[5] && ok[7]) ans++;
  
  dfs(num * 10 + 3);
  dfs(num * 10 + 5);
  dfs(num * 10 + 7);
}

int main() {
  cin >> n;
  dfs(0);
  cout << ans << endl;
}