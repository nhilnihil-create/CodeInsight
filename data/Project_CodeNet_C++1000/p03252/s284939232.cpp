#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  string s, t;
  cin >> s >> t;

  vector<int> sv(26);
  vector<int> tv(26);
  rep(i, s.size()) {
    sv[s[i] - 'a']++;
    tv[t[i] - 'a']++;
  }
  sort(sv.begin(), sv.end());
  sort(tv.begin(), tv.end());

  rep(i, sv.size()) {
    if (sv[i] != tv[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}