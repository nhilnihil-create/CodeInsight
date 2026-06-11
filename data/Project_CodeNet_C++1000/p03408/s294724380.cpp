#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  map<string, int> mp;
  int n;
  cin >> n;
  rep(i, n) {
    string s;
    cin >> s;
    mp[s]++;
  }
  int m;
  cin >> m;
  rep(i, m) {
    string t;
    cin >> t;
    mp[t]--;
  }
  int ans = 0;
  for (auto a : mp) {
    ans = max(ans, a.second);
  }
  cout << ans << endl;
  return 0;
}