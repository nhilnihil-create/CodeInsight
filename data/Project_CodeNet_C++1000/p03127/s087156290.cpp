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

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i, N)
  {
    cin >> A[i];
  }

  int result = gcd(A[0], A[1]);
  for (int i = 2; i < N; i++)
  {
    result = gcd(result, A[i]);
  }

  cout << result << endl;

  return 0;
}
