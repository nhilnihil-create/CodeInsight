#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s; cin >> s;
  bool flag = 1;
  if (s.at(0) != 'A') flag = 0;
  ll tmp = 0;
  for (ll i = 2; i < s.size()-1; i++) {
    if (s.at(i) == 'C') tmp++;
  }
  if (tmp != 1) flag = 0;
  tmp = 0;
  rep(i, s.size()) {
    ll num = s.at(i)-'a';
    if (0<=num && num<26) tmp++;
  }
  if (tmp != s.size()-2) flag = 0;
  if (flag) cout << "AC" << endl;
  else cout << "WA" << endl;
}