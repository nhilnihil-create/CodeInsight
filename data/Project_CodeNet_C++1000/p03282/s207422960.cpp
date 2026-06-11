#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

int main(void)
{
  string s;
  ll k;
  cin >> s >> k;
  char res = '1';
  for (int i = 0; i < min((ll)s.size(), k); ++i) {
    if (s[i] != '1') {
      res = s[i];
      break;
    }
  }
  cout << res << endl;
}