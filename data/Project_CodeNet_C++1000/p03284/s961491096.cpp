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

  if (N % K == 0)
    cout << 0 << endl;
  else
    cout << 1 << endl;

  return 0;
}
