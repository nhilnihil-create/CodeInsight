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
  int A, B, T;
  cin >> A >> B >> T;

  cout << T / A * B << endl;

  return 0;
}
