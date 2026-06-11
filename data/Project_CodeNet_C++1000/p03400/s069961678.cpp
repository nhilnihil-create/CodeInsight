#include <iostream>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  REP(i, N) {
    int A; cin >> A;
    for (int j = 1; j <= D; j++) {
      if (j*A + 1 <= D) X++;
    }
  }
  X += N;
  cout << X << endl;
  return 0;
}