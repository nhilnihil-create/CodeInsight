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
  int A, B, C;
  cin >> A >> B >> C;
  if (A + B >= C) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
