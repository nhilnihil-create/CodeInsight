#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

int in() { int x; scanf("%d", &x); return x; }
template<typename T> void pv(T a, T b) { for (T i = a; i < b; i++) cout << *i << ' '; cout << endl; }
template<typename T, typename U> void chmin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> void chmax(T &x, U y) { if (x < y) x = y; }

int N;
int a[100010];

int abs(int a, int b) {
  int c = a - b;
  return c < 0 ? -c : c;
}

int main() {
  int mx = 0;
  N = in();
  REP(i,N) {
    a[i] = in();
    chmax(mx, a[i]);
  }

  int res = 0;
  int dist = (1<<29);
  int mid = mx / 2;
  REP(i,N) if (a[i] != mx) {
    int t = abs(a[i] - mid);
    if (t < dist) {
      chmin(dist, t);
      res = a[i];
    }
  }

  cout << mx << ' ' << res << endl;

  return 0;
}

