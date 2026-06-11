#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  double n, k;
  cin >> n >> k;
  double ans = 0;
  double r = 1 / n;
  reps(i, 1, n+1) {
    if (k <= i) {
      ans += r;
      continue;
    } else {
      double rr = r;
      double v = i;
      while(v < k) {
        rr *= 0.5;
        v*=2;
      }
      ans += rr;
    }
  }
  printf("%.10f", ans);
  return 0;
}