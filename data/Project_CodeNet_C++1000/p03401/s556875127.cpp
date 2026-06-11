#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  A.insert(A.begin(), 0);
  A.insert(A.end(), 0);
  N += 2;
  int sum = 0;
  for (int i = 1; i < N; i++) {
    sum += abs(A.at(i - 1) - A.at(i));
  }
  for (int i = 1; i + 1 < N; i++) {
    int tmp1 = abs(A.at(i - 1) - A.at(i)) + abs(A.at(i + 1) - A.at(i));
    int tmp2 = abs(A.at(i - 1) - A.at(i + 1));
    cout << sum - tmp1 + tmp2 << "\n";
  }
}