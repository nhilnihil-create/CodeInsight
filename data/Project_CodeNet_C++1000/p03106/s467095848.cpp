#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int A, B, K;
  cin >> A >> B >> K;
  int min;
  
  if( A > B )
    min = B;
  else
    min = A;
  
  int count = 0;

  for( int i = min; i >= 0; i-- ) {
    if( A % i == 0 && B % i == 0 ) {
      count++;
    }
    if( count == K ) {
      cout << i << endl;
      break;
    }
  }
}