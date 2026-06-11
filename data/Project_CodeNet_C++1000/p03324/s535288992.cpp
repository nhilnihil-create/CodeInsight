#include <iostream>
using namespace std;
int main()
{
  int D, N;
  cin >> D >> N;
  int base = 1;
  for (int i = 0; i < D; i++) base *= 100;
  if (N < 100) {
    cout << base * N << endl;
  } else { // N=100
    cout << base * (N+1) << endl;
  }
  return 0;
}
