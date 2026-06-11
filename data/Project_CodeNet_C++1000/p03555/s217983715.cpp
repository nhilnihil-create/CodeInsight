#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  string s[2];
  cin >> s[0] >> s[1];

  string s2[2];
  s2[0] = s[1];
  s2[1] = s[0];
  reverse(s2[0].begin(), s2[0].end());
  reverse(s2[1].begin(), s2[1].end());

  if (s2[0] == s[0] && s2[1] == s[1]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
  return 0;
}