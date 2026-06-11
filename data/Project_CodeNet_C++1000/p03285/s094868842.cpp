#include <iostream>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  for (int i = 0; i <= N / 4; ++i) {
    for (int j = 0; j <= N / 7; ++j) {
      int M = 4 * i + 7 * j;
      if (N == M) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}