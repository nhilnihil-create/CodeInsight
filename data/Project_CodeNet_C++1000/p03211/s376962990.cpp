#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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

  int mn = 999;
  rep(i, S.size() - 2)
  {
    string s = S.substr(i, 3);
    int X = std::stoi(s);
    int diff = std::abs(X - 753);
    if (mn > diff)
      mn = diff;
  }

  cout << mn << endl;

  return 0;
}
