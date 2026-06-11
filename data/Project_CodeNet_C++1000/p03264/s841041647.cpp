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
  int K;
  cin >> K;

  cout << K / 2 * (K - K / 2) << endl;

  return 0;
}
