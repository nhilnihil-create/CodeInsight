#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  for (ll i = n; i < 1000; i++) {
    string s = to_string(i);
    if (s.at(0)==s.at(1) && s.at(1)==s.at(2)) {
      cout << i << endl;
      break;
    }
  }
}