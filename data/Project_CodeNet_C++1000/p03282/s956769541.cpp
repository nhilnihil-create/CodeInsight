#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

string s;
ll k;
ll num, len;


int main() {
  cin >> s >> k;
  len = 1000000000000000001;
  rep (i, s.size()) {
    if (s[i] != '1') {
      num = s[i] - '0';
      len = i + 1;
      break;
    }
  }
  if (k < len) {
    cout << 1 << endl;
  } else {
    cout << num << endl;
  }
  return 0;
}
