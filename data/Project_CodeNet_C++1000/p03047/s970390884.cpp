#include <iostream>
using namespace std;

int K, N;

int main() {
  cin >> N >> K;

  int result = 0;
  for (int i=1; i<=N; i++) {
    bool isValid = true;
    for (int j=0; j<K; j++) {
      if (i+j > N) {
        isValid = false;
        break;
      }
    }
    if (isValid) {
      ++result;
    }
  }
  cout << result << endl;

  return 0;
}