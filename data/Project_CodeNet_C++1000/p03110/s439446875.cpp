#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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

  long double sum = 0;
  rep(i, N)
  {
    string x;
    string u;
    cin >> x >> u;
    if (u == "JPY")
    {
      sum += std::stoi(x);
    }
    else
    {
      sum += std::stold(x) * 380000.0f;
    }
  }

  cout << std::fixed << std::setprecision(10) << sum << endl;

  return 0;
}
