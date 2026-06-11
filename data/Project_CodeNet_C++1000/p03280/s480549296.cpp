#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int A, B;
  cin >> A >> B;
  cout << A * B - A - B + 1 << endl;

  return 0;
}
