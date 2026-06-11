#include <iostream>
using namespace std;

int main() {
  int N;
  int A[210];
  int count = 0;
  bool isLoop = true;

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> A[i];

  while(isLoop) {
    bool isEven = true;

    for (int i = 0; i < N; ++i) {
      if (A[i] % 2 != 0) isEven = false;
    }

    if (isEven) {
      for (int i = 0; i < N; ++i) A[i] /= 2;
      ++count;
    } else { isLoop = false; }
  }

  cout << count << endl;
}