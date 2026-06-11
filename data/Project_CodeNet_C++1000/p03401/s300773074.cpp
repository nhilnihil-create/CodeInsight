#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;

  vector<int> A(N);
  long long all = 0;
  long long current = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    all += abs(current - A[i]);
    current = A[i];
  }

  all += abs(current - 0);
  current = 0;

  for (int i = 0; i < N; i++) {
    int answer = all;
    answer -= abs(current - A[i]);
    if (i != N - 1) {
      answer -= abs(A[i] - A[i+1]);
      answer += abs(current - A[i+1]);
    } else {
      answer -= abs(A[i] - 0);
      answer += abs(current - 0);
    }
    current = A[i];
    
    cout << answer << endl;
  }

  return 0;

}