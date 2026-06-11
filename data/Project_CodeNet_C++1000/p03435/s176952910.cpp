#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  vector <vector <ll>> v(3, vector <ll> (3));
  rep(i, 3) {
    rep(j, 3) {
      cin >> v.at(i).at(j);
    }
  }
  bool flag = 0;
  if (v.at(0).at(0)-v.at(0).at(1) == v.at(1).at(0)-v.at(1).at(1)) {
    if (v.at(1).at(0)-v.at(1).at(1) == v.at(2).at(0)-v.at(2).at(1)) {
      if (v.at(0).at(1)-v.at(0).at(2) == v.at(1).at(1)-v.at(1).at(2)) {
        if (v.at(1).at(1)-v.at(1).at(2) == v.at(2).at(1)-v.at(2).at(2)) {
          flag = 1;
        }
      }
    }
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}