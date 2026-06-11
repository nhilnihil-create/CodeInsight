
#include <iostream>
using namespace std;

int main()
{
  int R;
  cin >> R;
  char AxC[] = "AxC";
  char & x = AxC[1];
  if (R < 1200)
    x = 'B';
  else if (R < 2800)
    x = 'R';
  else
    x = 'G';
  cout << AxC;
  return 0;
}
