#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int A, B, C;
  cin >> A >> B >> C;

  if ( max( { A, B, C } ) == min( { A, B, C } ) )
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return ( 0 );
}