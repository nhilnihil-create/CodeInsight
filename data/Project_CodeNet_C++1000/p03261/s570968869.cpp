#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int N;
  cin >> N;
  char prev = '\0';
  set<string> s;
  bool ans = true;
  rep(i, 0, N) {
    string w;
    cin >> w;

    if (s.find(w) != s.end()) ans = false;
    s.insert(w);

    if (prev != '\0' && prev != w[0]) ans = false;
    prev = w[w.size() - 1];
  }

  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
