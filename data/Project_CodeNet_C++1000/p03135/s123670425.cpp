#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  long double T, X;
  cin >> T >> X;

  cout << std::fixed << std::setprecision(7) << T / X << endl;

  return 0;
}
