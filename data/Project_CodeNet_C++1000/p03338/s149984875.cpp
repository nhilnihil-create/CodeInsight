/**
 *    author:  lets
 *    created: 2020-06-07 18:08:54 JST
 **/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(n - 1, 0);
  for (int i = 0; i < n - 1; i++) {
    string t = s.substr(0, i + 1);
    string u = s.substr(i + 1);
    map<char, bool> ct, cu;
    for (auto tt : t) {
      ct[tt] = 1;
    }
    for (auto uu : u) {
      cu[uu] = 1;
    }
    for (auto ctt : ct) {
      if (cu.count(ctt.first) == 1) cnt[i]++;
    }
  }
  cout << *max_element(cnt.begin(), cnt.end()) << '\n';
  return 0;
}