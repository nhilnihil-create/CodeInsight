// ABC_119_A

#include <iostream>
using namespace std;

int main()
{
  string s;
  cin >> s;

  string tmp = "2019/04/30";

  if (s <= tmp) cout << "Heisei" << "\n";
  else cout << "TBD" << "\n";

  return 0;
  
}
