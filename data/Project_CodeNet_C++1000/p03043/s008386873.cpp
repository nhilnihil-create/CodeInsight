#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, k;
  cin >> n >> k;
  double ans = 0;
  for(int i = 1; i <= n; i++) {
    double tmp = i;
    double p = 1.0 / n;
    while(tmp < k) {
      tmp*= 2;
      p /= 2.0;
    }
    ans += p;
  }
  printf("%.10f", ans);
  return 0;
}