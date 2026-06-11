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
  int N, M;
  cin >> N >> M;

  int prob = 1 << M;
  cout << (100 * (N-M) + 1900 * M) * prob << endl;

  return 0;
}
