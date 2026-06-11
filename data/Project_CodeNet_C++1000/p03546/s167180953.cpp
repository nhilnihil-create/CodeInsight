#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll h, w;
  cin >> h >> w;
  vector <vector <ll>> v(10, vector <ll> (10));
  rep(i, 10) {
    rep(j, 10) {
      cin >> v.at(i).at(j);
    }
  }
  rep(k, 10) {
    rep(i, 10) {
      rep(j, 10) {
        v.at(i).at(j) = min(v.at(i).at(j), v.at(i).at(k)+v.at(k).at(j));
      }
    }
  }
  ll res = 0;
  rep(i, h) {
    rep(j, w) {
      ll a;
      cin >> a;
      if (a == -1) continue;
      else res += v.at(a).at(1);
    }
  }
  cout << res << endl;
}