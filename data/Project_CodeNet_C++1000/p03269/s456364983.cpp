#include <bits/stdc++.h>

using namespace std;

int N, L;
vector<tuple<int, int, int>> g;

void solve(int L) {
  if (L == 1) {
    N = 1;
    return;
  }
  if (L % 2) {
    solve(L - 1);
    g.emplace_back(1, N, L - 1);
  } else {
    solve(L / 2);
    g.emplace_back(N, N + 1, 0);
    g.emplace_back(N, N + 1, L / 2);
    ++N;
  }
}

int main() {
  cin >> L;
  solve(L);
  printf("%d %d\n", N, (int)g.size());
  for (const auto &p : g) {
    cout << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << '\n';
  }
}
