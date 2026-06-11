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

  if (B % A == 0)
    cout << A + B << endl;
  else
    cout << B - A << endl;

  return 0;
}
