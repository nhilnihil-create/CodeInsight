#include <iostream>
#include <queue>

typedef long long ll;
int N;

int main() {
  std::cin >> N;
  ll rem = (1LL << 60), asum = 0;
  bool all_same = true;

  for (int i = 0; i < N; ++i) {
    ll a, b; std::cin >> a >> b;
    asum += a;
    if (a != b) all_same = false;
    if (a > b)  rem = std::min(rem, b);
  }
  if (all_same) rem = asum;
  std::cout << asum - rem << "\n";

  return 0;
}
