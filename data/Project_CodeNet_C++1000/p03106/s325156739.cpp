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
  int A, B, K;
  cin >> A >> B >> K;

  int num = 0;
  for (int i = 100; i > 0; i--)
  {
    if (A % i == 0 && B % i == 0)
      num++;
    if (num == K)
    {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
