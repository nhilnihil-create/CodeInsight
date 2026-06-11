#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, bool>;
const int INF = 1000000007;

int main() {
  double n, k;
  cin >> n >> k;
  double total = 0;
  for (int i = 1; i <= n; i++) {
    double t = i;
    int cnt = 0;
    while (t < k) {
      t *= 2;
      cnt++;
    }
    double now = (double)(1 / n);
    now *= (double)pow(0.5, cnt);
    total += now;
  }
  printf("%.10f\n", total);
}