#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

constexpr unsigned Mod = 1000000007;

constexpr unsigned Add(unsigned a, unsigned b) { return (a + b) % Mod; }

int main() {
  int N;
  scanf("%d", &N);
  static char S[3000];
  scanf("%s", S);
  static unsigned F[3000];
  fill(F, F + N, 1);
  for (auto i = 1; i < N; ++i) {
    if (S[i - 1] == '<')
      for (auto j = 1; j < N - i; ++j)
        F[j] = Add(F[j - 1], F[j]);
    else {
      auto f = exchange(F[N - i - 1], F[N - i]);
      for (auto j = N - i - 2; j >= 0; --j)
        f = exchange(F[j], Add(f, F[j + 1]));
    }
  }
  printf("%u\n", F[0]);
  return 0;
}
