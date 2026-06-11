#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool match(int n)
{
  std::set<int> num;
  while (n > 0)
  {
    num.insert(n % 10);
    n /= 10;
  }

  if (num.size() == 3)
    return true;
  else
    return false;
}

int main()
{
  int N;
  cin >> N;

  int sum = 0;
  std::queue<long long> q;
  q.push(3);
  q.push(5);
  q.push(7);
  while (!q.empty())
  {
    long long n = q.front();
    q.pop();
    if (n > N)
      continue;
    if (match(n))
    {
      sum++;
    }
    q.push(n * 10 + 3);
    q.push(n * 10 + 5);
    q.push(n * 10 + 7);
  }

  cout << sum << endl;

  return 0;
}
