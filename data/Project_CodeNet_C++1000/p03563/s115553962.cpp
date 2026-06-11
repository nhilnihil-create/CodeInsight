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
  int R, G;
  cin >> R >> G;

  cout << 2 * G - R << endl;

  return 0;
}
