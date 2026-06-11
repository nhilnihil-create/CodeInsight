#include <iostream>
#include <vector>
using namespace std;

bool canBuy(int N) {
  for (int i = 0; i <= N / 4; i++) {
    for (int j = 0; j <= N / 7; j++) {
      if (i * 4 + j * 7 == N) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  cout << (canBuy(N) ? "Yes" : "No") << endl;
  return 0;
}