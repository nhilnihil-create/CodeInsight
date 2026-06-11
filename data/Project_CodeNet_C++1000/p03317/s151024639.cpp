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
  int N, K;
  cin >> N >> K;

  int pos = 0;
  int a;
  rep(i, N)
  {
    cin >> a;
    if (a == 1)
    {
      pos = i;
    }
  }

  int sum = 0;
  int left = pos;
  int right = N - pos - 1;

  sum += left / (K - 1);
  sum += right / (K - 1);

  int mod_l = left % (K - 1);
  int mod_r = right % (K - 1);
  if (0 < mod_l + mod_r && mod_l + mod_r <= K - 1)
    sum++;
  else
  {
    if (mod_l > 0)
      sum++;
    if (mod_r > 0)
      sum++;
  }

  cout << sum << endl;

  return 0;
}
