#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int a, b;
  cin >> a >> b;

  int count = a - 1;
  if (b >= a) count++;

  cout << count << endl;

  return 0;
}
