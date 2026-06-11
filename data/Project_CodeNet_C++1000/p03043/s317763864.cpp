#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> dice(n+1);
  for (int i = 1; i <= n; ++i) {
    int d = i;
    int c = 0;
    while (d < k) {
      d *= 2;
      ++c;
    }
    dice[i] = c;
  }

  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += pow(0.5, dice[i]);
  }
  ans /= n;
  printf("%.10f\n", ans);
  return 0;
}