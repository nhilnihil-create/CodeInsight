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

  bool buy = false;
  for (int i = 0; i <= N / 4; i++)
  {
    int n = N - i * 4;
    if (n % 7 == 0)
    {
      buy = true;
      break;
    }
  }

  if (buy)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
