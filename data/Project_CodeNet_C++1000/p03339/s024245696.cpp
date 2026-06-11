#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  vector <char> v(n);
  ll e = 0;
  rep(i, n) {
    cin >> v.at(i);
    if (v.at(i) == 'E') e++;
  }
  ll res = INF, w = 0;;
  rep(i, n) {
    if (v.at(i) == 'E') {
      e--;
      res = min(res, e+w);
    } else {
      res = min(res, e+w);
      w++;
    }
  }
  cout << res << endl;
}