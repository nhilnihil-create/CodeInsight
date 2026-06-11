#include <iostream>

using namespace std;

int main(void) {
  int N, C, D;
  cin >> N;
  C = (N / 4) + 1;
  D = (N / 7) + 1;

  for (int i = 0; i < C; i++) {
    for (int j = 0; j < D; j++) {
      if(N == i * 4 + j * 7){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}