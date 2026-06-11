#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
  int a,b,k;
  int i;

  cin >> a >> b >> k;

  for ( int i = a; i < a+k; ++i ) {
    if ( i > b ) break;
    cout << i << endl;
  }

  for ( int i = b-k+1; i <= b; ++i ) {
    if ( i < a+k ) continue;
    cout << i << endl;
  }

}
