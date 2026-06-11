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
  int n;
  cin >> n;
  vector<int> v;
  while (n > 0)
  {
    if (n % 10 == 9)
      v.emplace_back(1);
    else
      v.emplace_back(9);

    n /= 10;
  }

  rep(i, v.size())
  {
    cout << v[v.size() - 1 - i];
  }
  cout << endl;

  return 0;
}
