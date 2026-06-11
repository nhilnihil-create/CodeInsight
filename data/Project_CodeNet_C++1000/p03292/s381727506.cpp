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

int main()
{
  vector<int> A(3);
  rep(i, 3) cin >> A[i];

  std::sort(A.begin(), A.end());

  int sum = A[1] - A[0] + A[2] - A[1];
  cout << sum << endl;

  return 0;
}
