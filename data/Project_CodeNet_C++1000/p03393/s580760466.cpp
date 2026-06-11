#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  string s;
  cin >> s;
  char cur = 'z';
  {
  int i = 0;
  while (i < s.size() && s[i] == 'z' - i) i++;
  if (i == 26) {
    cout << -1 << endl;
    return 0;
  }
  }

  vector<bool> used(256);
  for (char c : s) used[c] = true;
  char c = 'a';
  while (used[c]) c++;
  if (c <= 'z') {
    s += c;
    cout << s << endl;
    return 0;
  }

  used = vector<bool>(256);
  for (int i = s.size() - 1; i >= 0; --i) {
    for (char c = s[i] + 1; c <= 'z'; ++c) if (used[c]) {
      s[i] = c;
      for (int j = 0; j <= i; ++j) cout << s[j];
      cout << endl;
      return 0;
    }
    used[s[i]] = true;
  }

  return 0;
}
