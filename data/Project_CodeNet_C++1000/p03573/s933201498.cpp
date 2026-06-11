#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int result = (A == B) * C + (B == C) * A + (C == A) * B;
  cout << result << endl;
  return 0;
}
