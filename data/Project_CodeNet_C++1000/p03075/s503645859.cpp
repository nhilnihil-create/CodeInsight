#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  vector<int> x(5);
  int k;
  rep(i, 5) cin >> x[i];
  cin >> k;

  rep(i, 5)
  {
    for (int j = i + 1; j < 5; j++)
    {
      if (std::abs(x[i] - x[j]) > k)
      {
        cout << ":(" << endl;
        return 0;
      }
    }
  }

  cout << "Yay!" << endl;

  return 0;
}
