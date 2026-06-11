#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  for (ll i = 0; i < k; i++) {
    if (s[i] != '1') {
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  return 0;
}