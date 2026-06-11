#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;
 
int main() {
  double n,k;
  cin >> n >> k;
  double ans = 0;
 
  for (double i = 1; i <= n; i++) {
    double cnt = 1;
    double tmp = i;
    while(tmp < k) {
      tmp *= 2;
      cnt *= 2;
    }
    ans += ((1/n) * (1/cnt));
  }
  printf("%.12f\n", ans);
  return 0;
}