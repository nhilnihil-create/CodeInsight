#include <iostream>

#include <algorithm>
#include <utility>

using std::cin;
using std::cout;
using std::endl;

using std::sort;
using std::pair;

using int_pair = pair<int, int>;

static int
solve(int N, int M, int_pair ab[])
{
  sort(&ab[0], &ab[M]);
  int_pair ba[100000];
  int i = 0;
  for (int m = 0; m < M;)
  {
    int a = ab[m].first;
    ba[i].second = a;
    ba[i].first = ab[m].second;
    ++i;
    while (++m < M && ab[m].first == a)
    {
    }
  }
  sort(&ba[0], &ba[i]);
  int count = 0;
  for (int ii = 0; ii < i; ii++)
  {
    count++;
    int b = ba[ii].first;
    while (ii + 1 < i && ba[ii + 1].second < b)
    {
      ++ii;
    }
  }
  return count;
}

int
main()
{
  int N, M;
  cin >> N >> M;
  int_pair ab[100000];
  for (int m = 0; m < M; m++)
  {
    cin >> ab[m].first >> ab[m].second;
  }
  cout << solve(N, M, ab) << endl;
  return 0;
}
