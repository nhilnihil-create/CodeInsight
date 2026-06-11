#include <iostream>

using namespace std;

int main()
{
  char X,Y,tmp;

  cin >> X >> Y;

  if ( X == Y ) cout << "=" << "\n";
  else if ( X < Y ) cout << "<" << "\n";
  else cout << ">" << "\n";
}
