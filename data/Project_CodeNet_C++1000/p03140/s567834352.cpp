#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  string A, B, C;
  cin >> A >> B >> C;
  int c = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] == B[i] && A[i] == C[i]) {
      
    } else if ((A[i] == B[i] && A[i] != C[i]) || (B[i] == C[i] && A[i] != B[i]) || (A[i] == C[i] && A[i] != B[i])) {
      c++;
    } else {
      c += 2;
    }
  }
  cout << c << endl;
  return 0;
}
