#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, l;
  cin >> n >> l;
  deque <ll> d;
  rep(i, n) {
    ll a;
    cin >> a;
    d.push_back(a);
  }
  ll res = 0;
  rep(i, l+1) {
    rep(j, i+1) {
      deque <ll> sub_d = d;
      vector <ll> u;
      ll tmp = 0;
      rep(k, j) {
        if (sub_d.size()) {
          tmp += sub_d.front();
          u.push_back(sub_d.front());
          sub_d.pop_front();
        }
      }
      rep(k, i-j) {
        if (sub_d.size()) {
          tmp += sub_d.back();
          u.push_back(sub_d.back());
          sub_d.pop_back();
        }
      }
      sort(u.begin(), u.end());
      rep(k, l-i) {
        if (k < u.size()) {
          if (u.at(k) < 0) tmp -= u.at(k);
        }
      }
      res = max(res, tmp);
    }
  }
  cout << res << endl;
}