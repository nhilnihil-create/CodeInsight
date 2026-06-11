#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  bool ok = true;
  if (s[0] != 'A') ok = false;
  int c = 0;
  for (int i = 2; i < s.size() - 1; ++i) if (s[i] == 'C') ++c;
  if (c != 1) ok = false;
  c = 0;
  rep(i, s.size()) if (s[i] >= 'a' && s[i] <= 'z') ++c;
  if (c != s.size() - 2) ok = false;
  if (ok) cout << "AC" << endl;
  else cout << "WA" << endl; 
  return 0;
}