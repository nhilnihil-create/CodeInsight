#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <iomanip> // std::std::setprecision(X)
#include <limits>  //std::numeric_limits<int>::max(), min()

typedef long long ll;

int main (void) {

  ll N, K;
  std::cin >> N >> K;

  ll ans = 0;
  for(ll b = K+1; b<=N; b++) {
    ans += (N/b*std::max(0LL,b-K)+std::max(0LL,N%b-K+1));
    if ( K == 0 ) ans--;
  }

  std::cout << ans << std::endl;

  return 0;
}