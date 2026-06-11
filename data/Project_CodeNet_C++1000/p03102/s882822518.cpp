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
  int N, M, C;
  cin >> N >> M >> C;

  vector<int> B(M);
  rep(i, M) cin >> B[i];

  int sum = 0;
  rep(n, N)
  {
    int tmp = 0;
    rep(i, M)
    {
      int a;
      cin >> a;
      tmp += a * B[i];
    }
    if (tmp + C > 0)
      sum++;
  }

  cout << sum << endl;

  return 0;
}
