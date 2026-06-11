#include <iostream>
using namespace std;

int main()
{
  int rate;

  cin >> rate;

  if(rate < 1200)
  {
    cout << "ABC" << endl;
  }
  else if(rate < 2800 && rate >= 1200)
  {
    cout << "ARC" << endl;
  }
  else
  cout << "AGC" << endl;
}
