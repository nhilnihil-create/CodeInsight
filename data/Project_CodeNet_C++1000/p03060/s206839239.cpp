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

  vector<int> V(N);
  rep(i, N) cin >> V[i];
  vector<int> C(N);
  rep(i, N) cin >> C[i];

  int sum = 0;
  rep(i, N)
  {
    if (V[i] - C[i] > 0)
      sum += V[i] - C[i];
  }

  cout << sum << endl;

  return 0;
}
