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
  int mn = 1000000000;
  int mx = 1;

  int a;
  rep(i, N)
  {
    cin >> a;
    if (mn > a)
      mn = a;
    if (mx < a)
      mx = a;
  }

  cout << mx - mn << endl;

  return 0;
}
