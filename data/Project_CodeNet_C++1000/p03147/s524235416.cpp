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

  vector<int> h(N);
  rep(i, N) cin >> h[i];

  bool water = false;
  int sum = 0;
  rep(i, 101)
  {
    if (water)
    {
      sum++;
    }
    water = false;

    rep(j, N)
    {
      if (h[j] > 0)
      {
        water = true;
        h[j]--;
      }
      else if (water)
      {
        sum++;
        water = false;
      }
    }
  }

  cout << sum << endl;

  return 0;
}
