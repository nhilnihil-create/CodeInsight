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
  string S, T;
  cin >> S >> T;
  S += S;

  bool found = false;
  rep(i, S.size() - T.size() + 1)
  {
    if (S.substr(i, T.size()) == T)
    {
      found = true;
      break;
    }
  }

  if (found)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
