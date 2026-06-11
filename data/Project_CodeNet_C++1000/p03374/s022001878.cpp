#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-7)
#define INF (1<<25)
#define PI (acos(-1))

#define FOR(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define REP(i,n) FOR(i,0,n)

#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

ll x[100001], v[100001];

ll rmax1[1000001], rmax2[10000001];
ll lmax1[1000001], lmax2[10000001];

int main() {
  int n; ll c; cin >> n >> c;
  REP(i,n) cin >> x[i] >> v[i];

  ll vsum = 0;
  REP(i,n) {
    vsum += v[i];
    rmax1[i+1] = max(rmax1[i], vsum - x[i]);
    rmax2[i+1] = max(rmax2[i], vsum - 2*x[i]);
  }
  vsum = 0;
  REP(i,n) {
    vsum += v[n-1-i];
    lmax1[i+1] = max(lmax1[i], vsum - c + x[n-1-i]);
    lmax2[i+1] = max(lmax2[i], vsum - 2*c + 2*x[n-1-i]);
  }
  ll ans = 0;
  REP(i,n+1) {
    chmax(ans, rmax1[i] + lmax2[n-i]);
    chmax(ans, lmax1[i] + rmax2[n-i]);
  }
  cout << ans << endl;
  return 0;
}
