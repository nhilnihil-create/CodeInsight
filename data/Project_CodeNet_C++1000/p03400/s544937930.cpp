#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  int sum = N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++)
    for (int j = 1; j <= D; j++)
      if ((j * A.at(i) + 1) <= D)
        sum++;
      else
        break;
  cout << sum + X << endl;
  return 0;
}