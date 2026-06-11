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
  int A, B, C, K;
  cin >> A >> B >> C >> K;

  int mx = 0;
  mx = std::max(A, std::max(B, C));

  int sum = A + B + C - mx;
  rep(i, K) mx *= 2;
  sum += mx;

  cout << sum << endl;

  return 0;
}
