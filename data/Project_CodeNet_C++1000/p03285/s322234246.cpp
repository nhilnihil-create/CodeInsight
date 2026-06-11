#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  bool flag = 0;
  for (ll i = 0; i <= n; i += 4) {
    if ((n-i)%7 == 0) flag = 1;
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}