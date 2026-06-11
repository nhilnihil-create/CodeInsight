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
  int A, B, C;
  cin >> A >> B >> C;

  if (A == B) cout << C << endl;
  else if (A == C) cout << B << endl;
  else if (B == C) cout << A << endl;

  return 0;
}
