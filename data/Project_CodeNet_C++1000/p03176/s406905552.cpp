#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = int_fast64_t;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
struct FenwickTree {
  int N;
  vll bit;
  FenwickTree(int n) : N(n), bit(n+2, 0) {}
  void add(int i, ll a) {
    while(i <= N) {
      chmax(bit[i], a);
      i += (i & -i);
    }
  }
  ll sum(int i) {
    ll res = 0;
    while(i > 0) {
      chmax(res, bit[i]);
      i -= (i & -i);
    }
    return res;
  }
  int lower_bound(ll w) {
    int k = 1;
    while(k <= N) k *= 2;
    k /= 2;
    int x = 0;
    while(k > 0) {
      if(x+k <= N && bit[x+k] < w) {
        w -= bit[x+k];
        x += k;
      }
      k /= 2;
    }
    return x+1;
  }
};

void answer() {
  ll n; cin >> n;
  vector<ll> h(n), a(n);
  rep(i, n) cin >> h[i];
  rep(i, n) cin >> a[i];
  FenwickTree ft(n);
  ll maxv = 0;
  rep(i, n) {
    ll cur = ft.sum(h[i]-1) + a[i];
    ft.add(h[i], cur);
    chmax(maxv, cur);
  }
  cout << maxv << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}