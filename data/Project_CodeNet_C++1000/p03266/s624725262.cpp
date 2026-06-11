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
  int N, K;
  cin >> N >> K;

  int num1 = N / K;
  int num2 = 0;
  if (K % 2 == 0)
  {
    num2 += N / K;
    if (N % K >= K / 2)
    {
      num2++;
    }
  }

  long long sum = (long long)num1 * num1 * num1 + (long long)num2 * num2 * num2;

  cout << sum << endl;

  return 0;
}
