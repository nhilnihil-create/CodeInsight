#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int max_val = A[0];
  int max_idx = 0;
  int min_val = A[0];
  int min_idx = 0;
  for (int i = 1; i < N; i++) {
    if (max_val < A[i]) {
      max_val = A[i];
      max_idx = i;
    }
    if (min_val > A[i]) {
      min_val = A[i];
      min_idx = i;
    }
  }

  if (abs(max_val) >= abs(min_val)) {
    if (min_val < 0) {
      cout << 2 * (N - 1) << endl;
      for (int i = 1; i <= N; i++) {
        if (i != max_idx + 1)
          cout << max_idx + 1 << " " << i << endl;
      }
    } else {
      cout << N - 1 << endl;
    }
    for (int i = 1; i < N; i++) {
      cout << i << " " << i + 1 << endl;
    }
  } else {
    if (max_val > 0) {
      cout << 2 * (N - 1) << endl;
      for (int i = 1; i <= N; i++) {
        if (i != min_idx + 1)
          cout << min_idx + 1 << " " << i << endl;
      }
    } else {
      cout << N - 1 << endl;
    }
    for (int i = N; i > 1; i--) {
      cout << i << " " << i - 1 << endl;
    }
  }

  return 0;
}