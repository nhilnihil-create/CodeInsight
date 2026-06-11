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
  int A, B;
  cin >> A >> B;

  if (A > 8 || B > 8) cout << ":(" << endl;
  else cout << "Yay!" << endl;

  return 0;
}
