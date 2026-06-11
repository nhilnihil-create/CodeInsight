#include <iostream>
//#include <vector>
//#include <string>

typedef long long ll;
//const ll INF = (ll)1e18;

ll H, W;

int main()
{
  ll N;
  std::cin >> N >> H >> W;

  ll ans = (N - H + 1) * (N - W + 1);
  std::cout << ans << std::endl;

  return 0;
}
