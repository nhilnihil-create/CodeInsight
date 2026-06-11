#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, MAX = 1e6;
  cin >> N;
  vector<int> V;
  V.push_back(1);
  for (int i = 6; i <= MAX; i *= 6) {
    V.push_back(i);
  }
  for (int i = 9; i <= MAX; i *= 9) {
    V.push_back(i);
  }
  sort(V.begin(), V.end());
  vector<int> DP(MAX + 1, 2e9);
  DP.at(0) = 0;
  for (int i = 0; i < V.size(); i++) {
    for (int j = 0; j < MAX + 1; j++) {
      if (DP.at(i) != 2e9) {
        if (j + V.at(i) < MAX + 1) {
          DP.at(j + V.at(i)) = min(DP.at(j + V.at(i)), DP.at(j) + 1);
        }
      }
    }
  }
  cout << DP.at(N) << "\n";
}