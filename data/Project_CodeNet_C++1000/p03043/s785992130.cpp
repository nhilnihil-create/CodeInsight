#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    double ans = 0;
    for (int i = 1; i <= n; i++) {
      double l = (double)1/n;
      if (i >= k) {
        ans += l;
        continue;
      }
      int is = i;
      while (is < k) {
        is *= 2;
        l *= 0.5;
      }
      ans += l;
    }
    printf("%.10f\n", ans);
    return 0;
}