#include <iostream>

using namespace std;

int main(void) {
  int K;
  cin >> K;

  cout << (K / 2) * (K - (K / 2)) << endl;

  return 0;
}