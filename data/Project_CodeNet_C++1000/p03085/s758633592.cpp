#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  string res = "";
  rep(i, s.size()) {
    char c;
    switch (s[i]) {
      case 'A':
        c = 'T';
        break;
      case 'T':
        c = 'A';
        break;
      case 'G':
        c = 'C';
        break;
      case 'C':
        c = 'G';
        break;
    }
    res.push_back(c);
  }
  cout << res << endl;

  return 0;
}
