#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> V;
  V.push_back(1);
  for (int i = 6; i <= 1e6; i *= 6) V.push_back(i);
  for (int i = 9; i <= 1e6; i *= 9) V.push_back(i);
  vector<int> DP(N + 1, 2e9);
  DP.at(0) = 0;
  for (auto v : V) {
    for (int i = 0; i < N + 1; i++) {
      if (DP.at(i) != 2e9 && i + v < N + 1) {
        DP.at(i + v) = min(DP.at(i + v), DP.at(i) + 1);
      }
    }
  }
  cout << DP.at(N) << "\n";
}
