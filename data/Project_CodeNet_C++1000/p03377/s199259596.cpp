#include <iostream>

using namespace std;

int main()
{
  int a,b,x;

  cin >> a >> b >> x;

  if ( x < a ) cout << "NO\n";
  else if ( a+b < x ) cout << "NO\n";
  else cout << "YES\n";
}
