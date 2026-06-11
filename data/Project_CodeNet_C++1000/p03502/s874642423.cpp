#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int N, M;
  cin >> N;
  M = N;
  int sum = 0;
  while (M) {
    sum += M % 10;
    M /= 10;
  }
  if (N % sum == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
