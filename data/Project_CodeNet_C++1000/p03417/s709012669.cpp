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

  long long sum = (long long)N * M;
  if (N > 1 && M > 1) {
    sum -= 4;  // corners
    sum -= 2 * ((long long)N - 2 + M - 2);  // edges
  } else {
    if (N == 1 && M == 1) sum = 1;
    else {
      sum -= 2;  // edges
    }
  }

  cout << sum << endl;

  return 0;
}
