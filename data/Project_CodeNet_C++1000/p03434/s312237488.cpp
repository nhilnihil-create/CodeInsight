#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N;
  cin >> N;
  vector<int> A( N + 1 );
  int Alice = 0;
  int Bob = 0;
  
  for( int i = 0; i < N; i++ )
    cin >> A.at( i );

  sort( A.begin(), A.end(), greater<int>() );

  for( int i = 0; i < ( N + 1 ) / 2; i++ ) {
    Alice += A.at( 2 * i );
    Bob += A.at( 2 * i + 1 );
  }

  cout << Alice - Bob << endl;
}
    