#include <iostream>
using ll = long long;

ll f(int N, int K, int k)
{
  if (N < k) return 0;
  ll nk = (N - k) / K;
  if (k > 0) ++nk;
  return nk * nk * nk;
}

int main()
{
  int N, K;
  std::cin >> N >> K;
  
  ll ans = f(N, K, K);
  if (K % 2 == 0)
    ans += f(N, K, K/2);
  
  std::cout << ans << std::endl;
}
