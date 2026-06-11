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
  int N;
  cin >> N;

  if (N == 0)
  {
    cout << 0 << endl;
    return 0;
  }

  string result = "";
  bool plus = true;
  while (N != 0)
  {
    if (N % 2 != 0)
    {
      result = "1" + result;
      if (plus)
      {
        N--;
      }
      else
      {
        N++;
      }
    }
    else
    {
      result = "0" + result;
    }

    N /= 2;

    plus = !plus;
  }

  cout << result << endl;

  return 0;
}
