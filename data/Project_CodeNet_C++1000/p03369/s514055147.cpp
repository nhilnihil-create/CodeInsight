#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  string S;
  cin >> S;
  int price = 700;
  
  for( int i = 0; i < 3; i++ ) {
    if( S.at( i ) == 'o' )
      price += 100;
  }
  cout << price << endl;
  
}
  