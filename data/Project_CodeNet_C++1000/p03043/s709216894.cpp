#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int n,k;
  cin >> n >> k;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    double cnt = 1.0/n;
    ll score = i+1;
    while (score < k) {
      score *= 2;
      cnt /= 2;
    }
    ans += cnt;
  }
  printf("%.12lf\n", ans);
  return 0;
}
