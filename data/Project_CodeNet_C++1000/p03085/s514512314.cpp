#include <iostream>
using namespace std;

int main()
{
  char x;
  cin >> x;
  
  switch(x)
  {
    case 'A':
      cout << 'T' << endl;
      break;
    case 'C':
      cout << 'G' << endl;
      break;
    case 'G':
      cout << 'C' << endl;
      break;
    case 'T':
      cout << 'A' << endl;
      break;
  }
  
  return 0;
}