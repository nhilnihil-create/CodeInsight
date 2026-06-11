#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N, M;
  cin >> N >> M;

  vector<std::pair<int, int>> cans(N);
  rep(i, N)
  {
    int a, b;
    cin >> a >> b;
    cans[i] = std::make_pair(a, b);
  }

  std::sort(cans.begin(), cans.end());

  long long sum = 0;
  rep(i, cans.size())
  {
    long long yen = cans[i].first;
    long long num = cans[i].second;
    if (M > num)
    {
      sum += num * yen;
      M -= num;
    }
    else
    {
      sum += M * yen;
      break;
    }
  }

  cout << sum << endl;

  return 0;
}
