#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll a, b; cin >> a >> b;
  bool flag = 1;
  rep(i, a) {
    char c; cin >> c;
    ll tmp = c - '0';
    if (!(0<=tmp && tmp<=9)) flag = 0;
  }
  char c; cin >> c;
  if (c != '-') flag = 0;
  rep(i, b) {
    cin >> c;
    ll tmp = c - '0';
    if (!(0<=tmp && tmp<=9)) flag = 0;
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}