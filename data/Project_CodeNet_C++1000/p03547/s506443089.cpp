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
  char X, Y;
  cin >> X >> Y;

  if (X - Y > 0) cout << ">" << endl;
  else if (X == Y) cout << "=" << endl;
  else cout << "<" << endl;

  return 0;
}
