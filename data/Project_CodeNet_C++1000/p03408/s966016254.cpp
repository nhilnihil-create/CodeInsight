#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> mp;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    mp[s]++;
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    string t;
    cin >> t;
    mp[t]--;
  }
  int ans = 0;
  for (auto i = mp.begin(); i != mp.end(); ++i) {
    ans = max(ans, (int)i->second);
  }
  cout << ans << endl;
}