#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N, x;
  cin >> N >> x;
  vector<int> a( N );
  int count = 0;

  for( int i = 0; i < N; i++ )
    cin >> a.at( i );

  sort( a.begin(), a.end() );

  for( int i = 0; i < N - 1; i++ ) {
    if( x >= a.at( i ) ) {
    x -= a.at( i );
    count++;
    }
    else 
      break;
  }

  if( x == a.at( N - 1 ) )
    count++;

  cout << count << endl;

}
    