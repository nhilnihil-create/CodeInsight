#include <iostream>

using namespace std;

int main() {
  int D, N;
  cin >> D >> N;

  if (N % 100 == 0) ++N;
  while (D) N *= 100, --D;
  cout << N << endl;

  return 0;
}
