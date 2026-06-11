#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main() {
  string str;
  cin >> str;
  ll ans = 0;
  ll last = 0;
  for (ll i = 0; i < static_cast<ll>(str.size()) - 1; ++i) {
    if (str[i] == 'W') {
      ++last;
      continue;
    }
    if (str[i + 1] == 'B')
      continue;
    ans += i - last + 1;
    ++last;
    str[i+1] = 'B';
  }
  cout << ans << endl;
}
