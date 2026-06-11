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
  string S;
  cin >> S;

  int a = 10 * (S[0] - '0') + (S[1] - '0');
  int b = 10 * (S[2] - '0') + (S[3] - '0');
  if ((a == 0 || a > 12) && 1 <= b && b <= 12)
    cout << "YYMM" << endl;
  else if ((b == 0 || b > 12) && 1 <= a && a <= 12)
    cout << "MMYY" << endl;
  else if (a != 0 && b != 0 && !(a > 12 && b > 12))
    cout << "AMBIGUOUS" << endl;
  else
    cout << "NA" << endl;

  return 0;
}
