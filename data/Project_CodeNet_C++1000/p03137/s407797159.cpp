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
  const int shift = 10e5;
  int N, M;
  cin >> N >> M;

  vector<int> X(M);
  rep(i, M)
  {
    int x;
    cin >> x;
    X[i] = x + shift;
  }

  if (N >= M)
  {
    cout << 0 << endl;
    return 0;
  }

  std::sort(X.begin(), X.end());

  int sum = 0;
  vector<int> diff(M - 1);
  rep(i, M - 1)
  {
    diff[i] = X[i + 1] - X[i];
  }
  sum = X[M - 1] - X[0];

  std::sort(diff.begin(), diff.end());
  rep(i, N - 1)
  {
    sum -= diff[M - 2 - i];
  }

  cout << sum << endl;

  return 0;
}
