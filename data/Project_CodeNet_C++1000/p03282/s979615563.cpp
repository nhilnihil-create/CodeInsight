#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  --k;
  int i;
  char c;
  for (i = 0; i < s.size(); ++i) {
    if (s[i] != '1') {
      c = s[i];
      break;
    }
  }
  if (k < i) cout << '1' << endl;
  else cout << c << endl;
  return 0;
}