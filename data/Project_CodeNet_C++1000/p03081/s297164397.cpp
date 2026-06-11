#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int Emulate(int at, const string& s, const vector<int>& c, const vector<int>& d) {
  for (int i = 0; i < c.size(); ++i) {
    if (s[at] - 'A' != c[i]) continue;
    at += d[i];
    if (at < 0) return -1;
    if (at >= s.size()) return +1;
  }
  return 0;
}

int main()
{
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  vector<vector<int>> pos(26);

  for (int i = 0; i < n; ++i) pos[s[i] - 'A'].push_back(i);

  vector<int> c(m), d(m);

  for (int i = 0 ; i < m; ++i) {
    char ch, type;
    cin >> ch >> type;
    c[i] = ch - 'A';
    d[i] = type == 'L' ? -1 : +1;
  }

  //cerr << endl;
  //for (int i = 0; i < n; ++i) cerr << Emulate(i, s, c, d) << endl;
  //cerr << endl;

  int result = 0;

  for (int letter = 0; letter < 26; ++letter) {
    if (pos[letter].empty()) continue;
    if (Emulate(pos[letter][0], s, c, d) != -1) continue;
    int l = 0;
    int r = pos[letter].size();
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (Emulate(pos[letter][m], s, c, d) == -1) l = m; else r = m;
    }
    //cerr << char('A' + letter) << " to left: " << l + 1 << endl;
    result += l + 1;
  }

  for (int letter = 0; letter < 26; ++letter) {
    if (pos[letter].empty()) continue;
    if (Emulate(pos[letter].back(), s, c, d) != +1) continue;
    int l = -1;
    int r = pos[letter].size() - 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (Emulate(pos[letter][m], s, c, d) == +1) r = m; else l = m;
    }
    //cerr << char('A' + letter) << " to right: " << l + 1 << endl;
    result += pos[letter].size() - r;
  }

  cout << n - result << endl;
  return 0;
}
