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
  vector<int> t(5);
  rep(i, 5) cin >> t[i];

  int mn = 10;
  rep(i, 5)
  {
    if (t[i] % 10 < mn && t[i] % 10 != 0)
      mn = t[i] % 10;
  }

  int sum = 0;
  rep(i, 5)
  {
    sum += (t[i] + 9) / 10;
  }
  sum *= 10;

  sum -= 10;
  sum += mn;

  cout << sum << endl;

  return 0;
}
