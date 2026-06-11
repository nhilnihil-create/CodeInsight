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
  int N, A, B;
  cin >> N >> A >> B;

  cout << std::min(N*A, B) << endl;

  return 0;
}
