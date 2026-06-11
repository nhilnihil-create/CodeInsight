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

  if (A <= 5)
    cout << 0 << endl;
  else if (A <= 12)
    cout << B / 2 << endl;
  else
    cout << B << endl;

  return 0;
}
