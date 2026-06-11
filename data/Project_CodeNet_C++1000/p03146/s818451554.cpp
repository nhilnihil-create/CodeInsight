#include <iostream>
#include <string>
#include <vector>
#include <map>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int s;
  cin >> s;

  std::map<int, int> m;
  int i = 1;
  m[s] = 1;
  while (true)
  {
    if (m[s] > 1)
    {
      cout << i << endl;
      return 0;
    }
    if (s % 2 == 0)
    {
      s /= 2;
    }
    else
    {
      s = 3 * s + 1;
    }
    m[s]++;
    i++;
  }

  return 0;
}
