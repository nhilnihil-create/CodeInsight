#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;cin >> N;
  vector<int> A(N);int total = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    total += A.at(i);
  }
  double average = (double)total / N;
  double min_diff = 100;
  int answer;
  for (int i = 0; i < N; i++) {
    int x = A.at(i);
    double d = abs(x - average);
    if (d < min_diff) {
      min_diff = d;
      answer = i;
    }
  }
  cout << answer << endl;
}