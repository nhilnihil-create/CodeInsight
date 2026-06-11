#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int A, B, C, K;
  cin >> A >> B >> C >> K;

  int maxABC = max(A, max(B, C));
  int maxABCpowK = maxABC;
  while (K--) maxABCpowK *= 2;
  int answer = A + B + C - maxABC + maxABCpowK;
  cout << answer << endl;
  return 0;
}
