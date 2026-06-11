#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

string s;
int r, b;

int main() {
  cin >> s;
  r = 0; b = 0;
  rep (i, s.size()) {
    if (s[i] == '1') b++;
    if (s[i] == '0') r++;
  }
  cout << min(r, b) * 2 << endl;
  return 0;
}
