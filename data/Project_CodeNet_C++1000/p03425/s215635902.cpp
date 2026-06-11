#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;

  map<char, ll> mp;

  rep(i, n) {
    string s;
    cin >> s;
    mp[s[0]]++;
  }

  ll ans = 0;
  ans += mp['R'] * mp['C'] * mp['H'];
  ans += mp['A'] * mp['C'] * mp['H'];
  ans += mp['R'] * mp['A'] * mp['H'];
  ans += mp['C'] * mp['A'] * mp['R'];  // m~
  ans += mp['M'] * mp['C'] * mp['H'];
  ans += mp['M'] * mp['H'] * mp['R'];
  ans += mp['M'] * mp['C'] * mp['R'];  // A~
  ans += mp['M'] * mp['A'] * mp['H'];
  ans += mp['M'] * mp['A'] * mp['C'];
  ans += mp['M'] * mp['A'] * mp['R'];

  cout << ans;
  return 0;
}
