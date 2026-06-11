#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
const ll MAX = 2*(ll)pow(10, 5);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  vector <ll> v(5);
  ll k;
  rep(i, 5) cin >> v.at(i);
  cin >> k;
  bool flag = 1;
  rep(i, 5) {
    rep(j, 5) {
      if (abs(v.at(i)-v.at(j)) > k) flag = 0;
    }
  }
  if (flag) cout << "Yay!" << endl;
  else cout << ":(" << endl;
}