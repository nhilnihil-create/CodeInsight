/*************************************************************************
  >         File: D.cc
  >       Author: Yuan Lei
  >         Mail: yuanlei@indeed.com
  > Created Time: Sun 22 Oct 2017 09:28:32 PM JST
*************************************************************************/
#include <vector>
#include <cstdio>
#include <bitset>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

int main() {
  std::ios::sync_with_stdio(0);
  std::string s;
  std::cin >> s;
  int n = s.size();
  int st = 0;
  std::map<int, int> mp;
  mp[0] = 0;
  for (int i = 0; i < n; ++i) {
    st ^= (1 << (s[i] - 'a'));
    int hs = n + 1;
    if (mp.count(st)) {
      hs = mp[st];
    }
    int &ans = mp[st];
    ans = hs;
    for (int j = 0; j < 26; ++j) {
      int prev = st ^ (1 << j);
      if (mp.count(prev)) {
        ans = std::min(ans, mp[prev] + 1);
      }
    }
  }
  int ans = mp[st];
  if (ans == 0) ans = 1;
  std::cout << ans << std::endl;

  return 0;
}
