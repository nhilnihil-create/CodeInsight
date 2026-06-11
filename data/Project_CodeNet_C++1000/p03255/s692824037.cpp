#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int N;
  long long int X;
  std::cin >> N >> X;
  std::vector<long long int> x(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> x[i];
  }

  std::reverse(x.begin(), x.end());
  std::vector<long long int> cost(N);
  std::vector<long long int> pref(N + 1, 0);
  for (int i = 0; i < N; ++i) {
    cost[i] = 2 * i + 3;
    pref[i + 1] = pref[i] + x[i];
  }
  cost[0] = 5;

  long long int energy = 1ll << 60;
  for (int i = N; i >= 1; --i) {
    long long int ris = (N + i) * X;
    int it = 0;
    for (int k = 0; it < N; ++k) {
      int next_it = std::min(it + i, N);
      ris += cost[k] * (pref[next_it] - pref[it]);
      it = next_it;
      if ( ris > energy ) break;
    }
    energy = std::min(energy, ris);
  }
  std::cout << energy << std::endl;

  return 0;
}
