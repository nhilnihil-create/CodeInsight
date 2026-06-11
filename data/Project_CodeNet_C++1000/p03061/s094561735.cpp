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
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int main()
{
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i, N) cin >> A[i];

  if (N == 2)
  {
    cout << std::max(A[0], A[1]) << endl;
    return 0;
  }

  std::sort(A.begin(), A.end());
  int mn = 1000000000;
  int mn2 = 1000000000;

  vector<int> L(N + 1);
  vector<int> R(N + 1);
  L[0] = 0;
  R[N] = 0;
  rep(i, N)
  {
    L[i + 1] = gcd(L[i], A[i]);
    R[N - i - 1] = gcd(R[N - i], A[N - i - 1]);
  }

  int mx = 0;
  rep(i, N)
  {
    int gcd_ = gcd(L[i], R[i + 1]);
    if (mx < gcd_)
      mx = gcd_;
  }

  cout << mx << endl;

  return 0;
}
