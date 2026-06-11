#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  string s; cin >> s;
  ll n; cin >> n;
  bool flag = 1;
  rep(i, n) {
    if (s.at(i) != '1') {
      cout << s.at(i) << endl;
      flag = 0;
      break;
    }
  }
  if (flag) cout << 1 << endl;
}