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
  char b;
  cin >> b;

  switch (b)
  {
  case 'A':
    cout << "T" << endl;
    break;
  case 'T':
    cout << "A" << endl;
    break;
  case 'G':
    cout << "C" << endl;
    break;
  case 'C':
    cout << "G" << endl;
    break;
  }

  return 0;
}
