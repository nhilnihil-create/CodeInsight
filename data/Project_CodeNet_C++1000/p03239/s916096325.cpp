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
  int N, T;
  cin >> N >> T;

  int mn = 1001;

  rep(i, N)
  {
    int c, t;
    cin >> c >> t;
    if (t <= T && mn > c)
    {
      mn = c;
    }
  }

  if (mn == 1001)
  {
    cout << "TLE" << endl;
  }
  else
  {
    cout << mn << endl;
  }

  return 0;
}
