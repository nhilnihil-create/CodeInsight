#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  cout << std::min(A, B) + std::min(C, D) << endl;

  return 0;
}
