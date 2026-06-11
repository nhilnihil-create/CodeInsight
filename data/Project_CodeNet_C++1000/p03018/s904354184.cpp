#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.size();

  ll ans = 0;
  int lc = 0, buf = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (lc) {
      if (s[i] == 'B') buf++;
      else buf = 0;
    } else {
      if (s[i] == 'A') ans += buf;
      if (s[i] == 'B') buf = 0;
    }
    lc = s[i] == 'C';
  }

  cout << ans << endl;
}
