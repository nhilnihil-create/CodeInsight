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

#define abs(x) (x>0?(x):(-(x)))

int main() {
  int N; cin >> N;
  vector<int> a(N);
  REP(i,N) cin >> a[i];
  whole(sort, a);
  int n = a[N-1];
  int r = a[0];
  REP(i,N-1) if (abs((double)a[i] - n/2.0) < abs((double)r-n/2.0)) r = a[i];
  cout << n << " " << r << endl;
  return 0;
}
