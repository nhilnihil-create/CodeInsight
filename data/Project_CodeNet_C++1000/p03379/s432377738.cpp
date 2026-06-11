#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y;
  for (int &x : X) cin >> x;
  Y = X;
  sort(Y.begin(), Y.end());
  map<int, int> MA;
  for (int i = 0; i < N; i++) {
    MA[Y.at(i)] = (i < N / 2) ? Y.at(N / 2) : Y.at(N / 2 - 1);
  }
  for (auto x : X) cout << MA[x] << "\n";
}