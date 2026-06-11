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
  int A, B;
  cin >> A >> B;

  if (A * B % 2 == 0)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;

  return 0;
}
