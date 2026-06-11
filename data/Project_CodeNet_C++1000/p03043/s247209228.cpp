#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
const int INF = 100000000;
const int MAX_N = 100;
typedef pair<int , int> P;
typedef long long ll;
 
int main () {
  double N, K, ans;
  cin >> N >> K;
  ans = 0;
  for (int i = 1; i <= N; ++i) {
    double tmp1 = 1 / N;
    double tmp2 = i;
    for (;;) {
      if (tmp2 < K) {
        tmp1 *= 0.5;
        tmp2 *= 2;
      } else {
        break;
      }
    }
    ans += tmp1;
  }
  printf("%.12lf\n", ans);
  return 0;
}