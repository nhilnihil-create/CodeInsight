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
  long long x, y;
  cin >> x >> y;

  long long num = x;
  int count = 0;
  while(num <= y) {
    count++;
    num *= 2;
  }

  cout << count << endl;

  return 0;
}
