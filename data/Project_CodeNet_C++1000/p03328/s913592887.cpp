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
  int a, b;
  cin >> a >> b;

  int sum = 0;
  for(int i=1; i <= 999; i++) {
    if (i == b - a) break;
    sum += i;
  }

  cout << sum - a << endl;

  return 0;
}
