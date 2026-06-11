#include <iostream>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 5000;
int const inf = 1000000000;

int v[5 + nmax];
ll dp[5 + nmax];

int main() {
  int n, a, b;
  std::cin >> n >> a >> b;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  v[n + 1] = n + 1;
  for(int i = 1; i <= n + 1; i++) {
    int smax = -1, bigger = 0;
    dp[i] = 1LL * nmax * inf;
    for(int j = i - 1; 0 <= j; j--) {
      if(v[j] < v[i] && smax < v[j]) { 
        dp[i] = std::min(dp[i], dp[j] + 1LL * bigger * a + 1LL * (i - j - 1 - bigger) * b);
      }
      if(v[j] < v[i])
        smax = std::max(smax, v[j]);
      else
        bigger++;
    }
  }
  std::cout << dp[n + 1];
  return 0;
}
