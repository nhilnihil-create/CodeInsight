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
  int N, D, X;
  cin >> N >> D >> X;

  int sum = X;
  sum += N;
  int a;
  rep(i, N) {
    cin >> a;
    sum += (D - 1) / a;
  }

  cout << sum << endl;

  return 0;
}
