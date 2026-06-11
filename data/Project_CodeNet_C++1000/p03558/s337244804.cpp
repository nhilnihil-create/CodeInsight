#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int bfs(int k)
{
  int c = 1;
  deque<P> q;
  bool isReached[k];
  for (int i = 0; i < k; i++)
    isReached[i] = false;

  q.push_front(make_pair(1, 1));
  while (q.size() > 0)
  {
    auto p = *(q.begin());
    auto n = p.first;
    auto c = p.second;
    q.pop_front();
    isReached[n] = true;

    if (n % k == 0)
      return c;

    if (!isReached[(n * 10) % k])
      q.push_front(make_pair((n * 10) % k, c));

    if (!isReached[(n + 1) % k])
      q.push_back(make_pair((n + 1) % k, c + 1));
  }

  return -1;
}

int main()
{
  long k;
  cin >> k;
  auto ans = bfs(k);
  cout << ans << endl;
  return 0;
}
