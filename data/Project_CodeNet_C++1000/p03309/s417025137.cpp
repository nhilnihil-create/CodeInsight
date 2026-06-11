#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

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

  vector<int> A(N);
  rep(i, N)
  {
    int a;
    cin >> a;

    A[i] = a - (i + 1);
  }
  std::sort(A.begin(), A.end());
  int mid = A[N / 2];

  long long sum = 0;
  rep(i, N)
  {
    sum += std::abs(A[i] - mid);
  }

  cout << sum << endl;

  return 0;
}
