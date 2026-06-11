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

  int c = 0;
  int a;
  rep(i, N)
  {
    cin >> a;
    while (a % 2 == 0)
    {
      a /= 2;
      c++;
    }
  }

  cout << c << endl;

  return 0;
}
