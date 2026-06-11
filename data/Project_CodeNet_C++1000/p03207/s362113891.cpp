#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int sum = accumulate(A.begin(), A.end(), 0L);
  cout << sum - *max_element(A.begin(), A.end()) / 2 << "\n";
}