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

  // result = sum of (gdc - 1) mod Ai
  long long sum = 0;
  rep(i, N)
  {
    int a;
    cin >> a;
    sum += a - 1;
  }

  cout << sum << endl;

  return 0;
}
