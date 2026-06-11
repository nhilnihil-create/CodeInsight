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
  string S;
  cin >> S;

  int r = 0;
  for (const auto &c : S)
  {
    if (c == '0')
      r++;
  }

  cout << std::min(r, (int)S.size() - r) * 2 << endl;

  return 0;
}
