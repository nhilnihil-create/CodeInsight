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
  if (N == 1)
    cout << "Hello World" << endl;
  else
  {
    int A, B;
    cin >> A >> B;
    cout << A + B << endl;
  }

  return 0;
}
