#include <iostream>
#include <string>
#include <vector>

using ll = long long;
const ll INF = (ll)1e18 + 1;

int main()
{
  int N;
  std::cin >> N;

  ll min_num = INF;
  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    ll a, b;
    std::cin >> a >> b;
    sum += a;
    if (a > b) min_num = std::min(min_num, b);
  }

  ll ans;
  if (min_num == INF) {
    ans = 0;
  } else {
    ans = sum - min_num;
  }
  std::cout << ans << std::endl;
  return 0;
}
