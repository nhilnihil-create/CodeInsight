#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,k;
  cin >> n >> k;
  long double ans = 0;
  rep(i,1,n+1) {
    int t = i;
    long double p = (long double)1/(long double)n;
    while(t < k) {
      p *= (long double)0.5;
      t *= 2;
    }
    ans += p;
  }
  printf("%.10lf\n", (double)ans);
  return 0;
}
