#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  map<int, int> mp;
  mp[0] = 0;
  int cur = 0;
  vector<int> candi = {0};
  for (int i = 0; i < 26; i++) candi.push_back(1 << i);
  for (int i = 0; i < n; i++) {
    cur ^= (1 << (s[i] - 'a'));
    int res = 1 << 30;
    if (!mp.count(cur)) mp[cur] = res;
    for (int x : candi) {
      int y = x ^ cur;
      if (mp.count(y)) mp[cur] = min(mp[cur], mp[y] + 1);
    }
  }
  cout << (mp[cur] == 0 ? 1 : mp[cur]) << endl;
}