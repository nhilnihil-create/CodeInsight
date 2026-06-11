#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A, B;
  if (N & 1) {
    for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {
        if (i + j != N) {
          A.push_back(i);
          B.push_back(j);
        }
      }
    }
  } else {
    for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {
        if (i + j != N + 1) {
          A.push_back(i);
          B.push_back(j);
        }
      }
    }
  }
  cout << A.size() << "\n";
  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << " " << B[i] << "\n";
  }

  return 0;
}