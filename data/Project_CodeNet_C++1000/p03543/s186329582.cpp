#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define DD long double

#define M 1000000007
#define INF 1e18

void setIO(string s = "") { 
  cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (s.size()) s += ".in", freopen(s.c_str(), "r", stdin);
}

int tt = 1;
void solve() {
  string s;
  cin >> s;
  set<char> c1, c2;
  string s1 = s.substr(0, 3);
  string s2 = s.substr(1, 3);
  for (auto c : s1) c1.insert(c);
  for (auto c : s2) c2.insert(c);
  cout << ((c1.size() == 1 || c2.size() == 1) ? "Yes" : "No")  << endl;
}

int main() {
  setIO();
  while (tt--) {
    solve();
  }
  return 0;
}