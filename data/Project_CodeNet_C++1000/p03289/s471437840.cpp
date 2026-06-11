#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

string s;
bool bl = true;

int main() {
  cin >> s;
  if (s[0] != 'A') bl = false;
  int cnt = 0;
  for (int i = 2; i < s.size()-1; i++) {
    if (s[i] == 'C') cnt++;
  }
  if (cnt != 1) bl = false;
  if (bl) {
    cnt = 0;
    rep (i, s.size()) {
      if (s[i] <= 'Z') cnt++;
    }
    if (cnt != 2) bl = false;
  }
  cout << (bl ? "AC" : "WA") << endl;
  return 0;
}
