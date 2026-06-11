#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

bool digit(const char c) { return '0' <= c && c <= '9'; }

bool f(const string s, int a) {
  rep(i, 0, a) if (!digit(s[i])) return false;

  if (s[a] != '-') return false;

  rep(i, a + 1, s.size()) if (!digit(s[i])) return false;

  return true;
}

int main() {
  int A, B;
  cin >> A >> B;
  string S;
  cin >> S;

  if (f(S, A))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
