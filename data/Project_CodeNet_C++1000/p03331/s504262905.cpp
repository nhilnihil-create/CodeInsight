#include<bits/stdc++.h>
using namespace std;

int p( int x )
{
  int sum = 0;
  
  while( x ) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main( void )
{
  int N;
  cin >> N;
  int sum;
  int min = INT_MAX;

  int A, B;

  for( int i = 1; i < N; i++ ) {
    A = i;
    B = N - i;
    sum = p( A ) + p( B );
    if( sum < min )
      min = sum;
  }

  cout << min << endl;
}