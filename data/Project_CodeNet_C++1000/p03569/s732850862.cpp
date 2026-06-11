#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, ans = 0;
  string s;
  vector<char> c;
  cin >> s;
  rep(i, s.size()) if (s[i] != 'x') c.push_back(s[i]);
  bool ok = false;
  for (int i = 0; i < c.size() / 2; ++i) {
    if (c[i] == c[c.size() - 1 - i])
      continue;
    else
      ok = true;
  }

  if (s.size() == 1) {
    puts("0");
    return 0;
  }

  if (ok) {
    puts("-1");
    return 0;
  }
  deque<char> dqf, dqb;
  int i = 0, j = s.size() - 1;
  do {
    if (s[i] == s[j]) {
      dqf.push_back(s[i]);
      dqb.push_front(s[j]);
      i++, j--;
    } else {
      if (s[i] == 'x') {
        dqf.push_back(s[i]);
        dqb.push_front('x');
        i++;
        ans++;
      } else {
        dqf.push_back('x');
        dqb.push_front(s[j]);
        j--;
        ans++;
      }
    }
  } while (i <= j);

  cout << ans << endl;
  return 0;
}
