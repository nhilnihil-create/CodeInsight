#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n; cin >> n;
  bool flag = 0;
  rep(i, n) {
    char c; cin >> c;
    if (c == 'Y') {
      flag = 1;
      break;
    }
  }
  if (flag) cout << "Four" << endl;
  else cout << "Three" << endl;
}