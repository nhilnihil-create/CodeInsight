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
  
  if (a * b % 2 == 0) cout << "Even" << endl;
  else cout << "Odd" << endl;

  return 0;
}
