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
  int X;
  cin >> X;

  int perf = -1;
  for (int i = 2; i < X; i++) {
    int num = i * i;
    while (num <= X) {
      perf = std::max(perf, num);
      num *= i;
    }
  }
  if (perf == -1) perf = 1;

  cout << perf << endl;

  return 0;
}
