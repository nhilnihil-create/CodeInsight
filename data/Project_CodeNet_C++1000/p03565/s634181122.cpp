#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using pint = pair<int, int>;

int S = 0;
int T = 0;
string s, t;

bool match(int k) {
  rep(i, T) if (t[i] != s[i + k] && s[i + k] != '?') return false;
  return true;
}

string construct(int k) {
  string ans = s;
  rep(i, T) ans[k + i] = t[i];
  replace(ans.begin(), ans.end(), '?', 'a');
  return ans;
}

int main() {
  cin >> s >> t;
  S = s.size(), T = t.size();
  if (S < T) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  string ans = s;
  int k = 0;
  for (k = S - T; k >= 0; k--)
    if (match(k)) break;

  if (k >= 0)
    cout << construct(k) << endl;
  else
    cout << "UNRESTORABLE" << endl;

  return 0;
}
