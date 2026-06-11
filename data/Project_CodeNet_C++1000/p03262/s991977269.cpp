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

unsigned int gcd(unsigned int a, unsigned int b)
{
  if (a == 0)
    return b;
  else if (b == 0)
    return a;
  else if (a > b)
    return gcd(b, a % b);
  else
    return gcd(a, b % a);
}

int main()
{
  int N, X;
  cin >> N >> X;

  vector<int> x(N);
  rep(i, N)
  {
    cin >> x[i];
  }

  x.emplace_back(X);

  std::sort(x.begin(), x.end());

  int gcd_ = x[1] - x[0];
  rep(i, x.size() - 1)
  {
    gcd_ = gcd(gcd_, x[i + 1] - x[i]);
  }

  cout << gcd_ << endl;

  return 0;
}
