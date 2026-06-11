#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  ll n = s.size();

  ll ans = 0;
  ll b = 0;
  for (ll i = 0; i < n; i++) {
    if (s[i] == 'B') {
      b++;
    } else if(s[i]=='W') {
      ans += b;
    }
  }
  cout << ans;
  return 0;
}
