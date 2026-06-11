#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N;
  cin >> N;
  vector<int> A( N );

  int count = 0;
  
  for( int i = 0; i < N; i++ ) {
    cin >> A.at( i );
  }

  int ans = 0;
  while( 1 ) {
    for( int i = 0; i < N; i++ ) {
      if( A.at( i ) % 2 == 0 )
	count++;
    }
    
    if( count == N ) {
      for( int i = 0; i < N; i++ ) {
	A.at( i ) /= 2;
      }
	ans++;
      }
    else
      break;
    
    count = 0;
 
  }
  cout << ans << endl;
}
