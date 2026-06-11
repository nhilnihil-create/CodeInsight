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

  S = S.substr(5, 2);
  int m = std::stoi(S);
  if (m <= 4)
    cout << "Heisei" << endl;
  else
    cout << "TBD" << endl;

  return 0;
}
