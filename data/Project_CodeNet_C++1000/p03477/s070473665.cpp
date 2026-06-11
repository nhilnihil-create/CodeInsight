#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  A += B;
  C += D;
  if (A > C) cout << "Left" << endl;
  else if (A == C) cout << "Balanced" << endl;
  else cout << "Right" << endl;

  return 0;
}
