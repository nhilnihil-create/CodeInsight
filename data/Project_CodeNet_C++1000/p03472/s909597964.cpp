#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n, h; cin >> n >> h;
  vector <pair <ll, ll>> a(n, pair <ll, ll> ());
  vector <pair <ll, ll>> b(n, pair <ll, ll> ());
  rep(i, n) {
    cin >> a.at(i).first >> b.at(i).first;
    a.at(i).second = i; b.at(i).second = i;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll tmp_a = a.at(n-1).first, tmp_loc = a.at(n-1).second, tmp_b;
  rep(i, n) {
    if (b.at(i).second == tmp_loc) {
      tmp_b = b.at(i).first;
      break;
    }
  }
  ll res = 0;
  for (ll i = n-1; i >= 0; i--) {
    if (b.at(i).second != tmp_loc) {
      if (b.at(i).first > tmp_a) {
        h -= b.at(i).first;
        res++;
      }
    }
    if (h>0 && h-tmp_b<=0) {
      h = 0;
      res++;
    }
    if (h <= 0) break;
  }
  if (h > 0) {
    h -= tmp_b;
    res++;
    if (h > 0) {
      if (h%tmp_a) res += h/tmp_a+1;
      else res += h/tmp_a;
    }
  }
  cout << res << endl;
}