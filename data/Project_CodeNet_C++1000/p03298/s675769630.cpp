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

map<pair<string, string>, ll> GetMap(string s, bool rightHalf) {
  map<pair<string, string>, ll> result;
  int n = s.size();
  for (int mask = 0; mask < (1 << n); ++mask) {
    string s0, s1;
    for (int i = 0; i < n; ++i) if (!(mask & (1 << i))) s0 += s[i];
    for (int i = n - 1; i >= 0; --i) if (mask & (1 << i)) s1 += s[i];
    if (rightHalf) swap(s0, s1);
    result[make_pair(s0, s1)]++;
  }
  return result;
}

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<pair<string, string>, ll> left, right;
  left = GetMap(s.substr(0, n), false);
  right = GetMap(s.substr(n, n), true);
  ll result = 0;
  for (auto p : left) {
    if (p.second * right[p.first] > 0) {
      //cout << p.first.first << "," << p.first.second << " " << p.second * right[p.first] << endl;
    }
    result += p.second * right[p.first];
  }
  cout << result << endl;
  return 0;
}
