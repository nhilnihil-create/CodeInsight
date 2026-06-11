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
  int N, M;
  cin >> N >> M;

  vector<int> like(M, 0);

  rep(i, N)
  {
    int K;
    cin >> K;
    rep(j, K)
    {
      int a;
      cin >> a;
      a--;
      like[a]++;
    }
  }

  int sum = 0;
  rep(i, M)
  {
    if (like[i] == N)
      sum++;
  }

  cout << sum << endl;

  return 0;
}
