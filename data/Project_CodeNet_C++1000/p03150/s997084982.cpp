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

int FindPrefix(string s, string t) {
  int i = 0;
  while (i < s.size() && i < t.size() && s[i] == t[i]) i++;
  return i;
}

int main()
{
  string s;
  cin >> s;
  string t = "keyence";
  int prefix = FindPrefix(s, t);
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  int suffix = FindPrefix(s, t);
  cout << (prefix + suffix >= t.size() ? "YES" : "NO") << endl;
  return 0;
}
