// ABC_120_A

#include <iostream>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  if (a * c <= b) cout << c << "\n";
  else cout << (int) b / a << "\n";

  return 0;
  
}
