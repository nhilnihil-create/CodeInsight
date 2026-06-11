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

  int sum = 0;
  int mx = 0;
  rep(i, N)
  {
    int p;
    cin >> p;
    if (mx < p)
      mx = p;

    sum += p;
  }

  cout << sum - mx / 2 << endl;

  return 0;
}
