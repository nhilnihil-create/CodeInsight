#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;
  std::vector<long long> A(N);
  for (auto &i : A) { std::cin >> i; }
  for (int i = 0; i + 1 < N; ++i) { A[i + 1] += A[i]; }
  int split1 = 0;
  int split2 = 2;
  long long ans = 1000000000000;
  for (int i = 1; i + 2 < N; ++i) {
    while (split1 + 1 < i && A[split1] * 2 < A[i]) { ++split1; }
    split1 = split1 > 1 && A[i] - A[split1 - 1] < A[split1] ? split1 - 1 : split1;
    split2 = std::max(split2, i + 1);
    while (split2 + 1 < N && (A[split2] - A[i]) * 2 < (A[N - 1] - A[i])) { ++split2; }
    split2 = A[N - 1] - A[split2 - 1] < A[split2] - A[i] ? split2 - 1 : split2;
    split2 = std::max(split2, i + 1);
    auto P = A[split1];
    auto Q = A[i] - A[split1];
    auto R = A[split2] - A[i];
    auto S = A[N - 1] - A[split2];
    ans = std::min(ans, std::max({P, Q, R, S}) - std::min({P, Q, R, S}));
  }
  std::cout << ans << std::endl;
  return 0;
}