#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  const int mod = 1'000'000'007;

  int n;
  string s;
  cin >> n >> s;

  vector<int> v(26);
  for (char c : s) v[c-'a']++;

  ll ans = 1;
  for (int i : v)
  {
    ans *= i + 1;
    ans %= mod;
  }

  cout << ans - 1 << endl;
  return 0;
}
