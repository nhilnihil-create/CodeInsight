#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
  int max = 0, t = 0;
  vector<int> A(3, 0), abss(3, 0); cin >> A[0] >> A[1] >> A[2];
  abss[0] = abs(A[0] - A[1]);
  abss[1] = abs(A[1] - A[2]);
  abss[2] = abs(A[2] - A[0]);
  for(int i = 0; i < 3; i++) {
    if(max < abss[i]) max = abss[i];
    t += abss[i];
  }
  cout << t - max << endl;
  return 0;
}