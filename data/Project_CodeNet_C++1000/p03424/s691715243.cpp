#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int N;
  cin >> N;
  char c;
  set<char> sc;
  rep(i, 0, N) {
    cin >> c;
    sc.insert(c);
  }

  string ans = "Three";
  if (sc.size() == 4) ans = "Four";
  cout << ans << endl;

  return 0;
}
