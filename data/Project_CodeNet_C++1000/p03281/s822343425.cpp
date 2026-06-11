#include<bits/stdc++.h>
using namespace std;

int checkNum( int i );

int main( void )
{
  int N;
  cin >> N;
  int count = 0;

  for( int i = 1; i <= N; i++ ) {
    count += checkNum( i );
  }

  cout << count << endl;
}

int checkNum( int i )
{
  int count = 0;
  
  if( i % 2 == 0 ) {
    return 0;
  }

  for( int j = 1; j <= i; j++ ) {
    if( i % j == 0 )
      count++;
  }
  
  if( count == 8 )
    return 1;
  else
    return 0;
}
    