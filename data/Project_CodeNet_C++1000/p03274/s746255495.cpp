#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

  vector<int> left;
  vector<int> right;
  rep(i, N)
  {
    int x;
    cin >> x;
    if (x < 0)
      left.emplace_back(x);
    else if (x == 0)
      K--;
    else
      right.emplace_back(x);
  }

  std::reverse(left.begin(), left.end());

  long long mn = -1;
  int L = std::min(K, (int)left.size());

  if (K == 0)
  {
    cout << 0 << endl;
    return 0;
  }
  for (int l = 0; l <= L; l++)
  {
    if (K - l > right.size())
      continue;

    long long sum = 0;
    if (l == 0)
    {
      sum = right[K - 1];
    }
    else if (l == K)
    {
      sum = -left[K - 1];
    }
    else
    {
      sum = -left[l - 1] + right[K - l - 1];
      sum += std::min(-left[l - 1], right[K - l - 1]);
    }

    if (mn == -1 || mn > sum)
      mn = sum;
  }

  cout << mn << endl;

  return 0;
}
