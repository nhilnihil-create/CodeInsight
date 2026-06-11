#include <iostream>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int const nmax = 200000;
ll const inf = 1000000000000000000;

ll v[5 + nmax], sum[5 + nmax], sum2[5 + nmax];

ll solve(int n, int k) {
  ll result = 0;
  int start = n, coef = 1;
  while(1 <= start) {
    int nxt = std::max(0, start - k);
    ll coef2 = (1LL * (coef + 1) * (coef + 1) - 1LL * coef * coef);
    if(coef == 1)
      coef2 = 5;
    result += (sum[start] - sum[nxt]) * coef2;
    if(inf < result)
      return inf;
    start = nxt;
    coef++;
  }
  return result;
}

int main() {
  int n, x;
  std::cin >> n >> x;
  for(int i = 1;i <= n; i++) 
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    sum[i] = sum[i - 1] + v[i];
  sum2[1] = v[1];
  for(int i = 2;i <= n; i++) 
    sum2[i] = sum2[i - 2] + v[i];
  ll result = inf;
  for(int i = 1;i <= n; i++)
    result = std::min(result, solve(n, i) + 1LL * x * (n + i));
  std::cout << result;
}
