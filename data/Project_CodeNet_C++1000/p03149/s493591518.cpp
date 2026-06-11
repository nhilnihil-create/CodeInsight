#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 4;
  vector<int> V(N);
  for (int i = 0; i < N; i++) cin >> V.at(i);
  sort(V.begin(), V.end());
  cout << ((V.at(0) == 1 && V.at(1) == 4 && V.at(2) == 7 && V.at(3) == 9) ? "YES" : "NO") << "\n";
}