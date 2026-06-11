#include <iostream>
#include <string>
#include <vector>
#include <set>

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
  for (int i = N; i <= 999; i++)
  {
    int n = i;
    std::set<int> s;
    while (n > 0)
    {
      s.insert(n % 10);
      n /= 10;
    }

    if (s.size() == 1)
    {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
