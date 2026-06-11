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
  string S;
  cin >> S;

  int sum = 0;
  for (char c : S) {
    if (c == 'o') sum++;
  }

  cout << 700 + sum * 100 << endl;

  return 0;
}
