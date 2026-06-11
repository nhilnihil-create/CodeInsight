// 2020-08-11 20:39:11
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

const int MX = 100010;
priority_queue<P> que, que2; // d, t
int kind_count, ate_count[MX];
priority_queue<P, vector<P>, greater<P> > ate; // d, t
void answer() {
  int n, k;
  cin >> n >> k;
  rep(i, n) {
    int t, d;
    cin >> t >> d;
    que.emplace(P(d, t));
  }
  ll ans = 0;
  while(!que.empty()) {
    int d, t;
    tie(d, t) = que.top(); que.pop();
    if(ate_count[t] == 0) {
      if(kind_count < k) {
        ans += d;
        ate_count[t]++;
        kind_count++;
        ate.emplace(P(d, t));
      }
    } else {
      que2.emplace(P(d, t));
    }
  }
  int ki = kind_count;
  while(!que2.empty()) {
    int d, t;
    tie(d, t) = que2.top(); que2.pop();
    if(ki < k) {
      ki++;
      ans += d;
      ate_count[t]++;
    } else {
      int d2, t2;
      tie(d2, t2) = ate.top(); ate.pop();
      if(kind_count * 2 - 1 + d2 <= d) {
        ans -= d2;
        ate_count[t2]--;
        kind_count--;
        ans += d;
        ate_count[t]++;
      } else break;
    }
  }
  cout << ans + ll(kind_count) * kind_count << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}