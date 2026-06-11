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
  int D;
  cin >> D;
  string s;

  switch (D)
  {
  case 25:
    s = "Christmas";
    break;
  case 24:
    s = "Christmas Eve";
    break;
  case 23:
    s = "Christmas Eve Eve";
    break;
  case 22:
    s = "Christmas Eve Eve Eve";
    break;
  }

  cout << s << endl;

  return 0;
}
