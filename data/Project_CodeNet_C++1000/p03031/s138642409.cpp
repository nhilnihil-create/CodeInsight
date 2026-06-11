#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> circuit(M, vector<int>());
  for (int i{}; i < M; ++i) {
    int k;
    cin >> k;
    for (int j{}; j < k; ++j) {
      int s;
      cin >> s;
      --s;
      circuit[i].push_back(s);
    }
  }
  vector<int> p(M);
  for (int i{}; i < M; ++i) {
    cin >> p[i];
  }

  int ans{};
  for (int i{}; i < (1 << N); ++i) {
    vector<int> switches(N);
    for (int j{}; j < N; ++j) {
      switches[j] = !!(i & (1 << j));
    }
    bool bingo{true};
    for (int j{}; j < M; ++j) {
      int on{};
      for (const auto &s : circuit[j]) {
        on += switches[s];
      }
      if (on % 2 != p[j]) {
        bingo = false;
        break;
      }
    }
    if (bingo) ++ans;
  }

  cout << ans << endl;
  return 0;
}
