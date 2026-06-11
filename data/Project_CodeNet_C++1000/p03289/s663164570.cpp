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
  string S;
  cin >> S;

  bool has_A = false;
  bool has_C = false;
  rep(i, S.size())
  {
    if (S[i] == 'A')
    {
      if (i != 0 || has_A)
      {
        cout << "WA" << endl;
        return 0;
      }
      has_A = true;
    }
    else if (S[i] == 'C')
    {
      if (i < 2 || i >= S.size() - 1 || has_C)
      {
        cout << "WA" << endl;
        return 0;
      }
      has_C = true;
    }
    else if ('A' <= S[i] && S[i] <= 'Z')
    {
      cout << "WA" << endl;
      return 0;
    }
  }

  if (!has_A || !has_C)
  {
    cout << "WA" << endl;
    return 0;
  }

  cout << "AC" << endl;

  return 0;
}
