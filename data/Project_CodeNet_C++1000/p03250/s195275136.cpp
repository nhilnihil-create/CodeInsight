#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int A, B, C;
  cin >> A >> B >> C;

  cout << std::max({A, B, C}) * 9 + A + B + C << endl;
  return 0;
}
