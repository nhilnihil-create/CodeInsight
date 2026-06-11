#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> M(N);
  for (int i = 0; i < N; i++) cin >> M.at(i);
  int sum = accumulate(M.begin(), M.end(), 0);
  X -= sum;
  cout << N + X / *min_element(M.begin(), M.end()) << "\n";
}